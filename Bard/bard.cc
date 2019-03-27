#include <iostream>
#include <unordered_set>
using namespace std;

int Max(int* v, int n) {
  int max = -1;

  for (int i = 0; i < n; i++) {
    if (v[i] > max) {
      max = v[i];
    }
  }

  return max;
}

int main() {
  int n, e;
  cin >> n;
  cin >> e;
  int v[n] = {0};
  int c = 0;

  while (e--) {
    int k;
    cin >> k;
    unordered_set<int> s;

    while (k--) {
      int i;
      cin >> i;
      s.insert(i - 1);

      if (i == 1) {
        c++;
      }
    }

    if (s.find(0) != s.end()) {
      for (int i = 0; i < n; i++) {
        if (s.find(i) != s.end()) {
          v[i]++;
        }
      }
    } else {
      int max = Max(v, n);

      for (int i = 0; i < n; i++) {
        if (s.find(i) != s.end()) {
          v[i] = max;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (v[i] == c) {
      cout << i + 1 << endl;
    }
  }

  return 0;
}