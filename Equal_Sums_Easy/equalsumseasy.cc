#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define pb push_back

int main() {
  int t;
  cin >> t;

  for (int k = 0; k < t; k++) {
    int n;
    cin >> n;
    int a[n];

    for (int j = 0; j < n; j++) {
      cin >> a[j];
    }

    vector<vector<int>> v;
    for (int i = 0; i < (1 << n); i++) {
      vector<int> v2;

      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          v2.pb(a[j]);
        }
      }

      v.pb(v2);
    }

    unordered_map<int, vector<int>> um;
    bool pos = false;

    for (int i = 0; i < v.size(); i++) {
      int sum = 0;

      for (int j = 0; j < v[i].size(); j++) {
        sum += v[i][j];
      }

      if (um.find(sum) != um.end()) {
        cout << "Case #" << k + 1 << ": " << endl;

        for (int l = 0; l < um[sum].size(); l++) {
          cout << um[sum][l] << ' ';
        }

        cout << endl;

        for (int l = 0; l < v[i].size(); l++) {
          cout << v[i][l] << ' ';
        }

        cout << endl;
        pos = true;

        break;
      }

      um.insert({sum, v[i]});
    }

    if (!pos) {
      cout << "Case #" << k + 1 << ": " << endl;
      cout << "Impossible" << endl;
    }
  }

  return 0;
}