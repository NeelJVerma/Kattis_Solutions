#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <set>
using namespace std;

bool IsPrime(int n) {
  if (n <= 1) {
    return false;
  }

  if (n <= 3) {
    return true;
  }

  if (!(n % 2) || !(n % 3)) {
    return false;
  }

  for (int i = 5; (i * i) <= n; i += 6) {
    if (!(n % i) || !(n % (i + 2))) {
      return false;
    }
  }

  return true;
}

int Solve(string s) {
  set<string> all;
  sort(s.begin(), s.end());

  do {
    for (int i = 1; i <= s.length(); i++) {
      all.insert(s.substr(0, i));
    }
  } while (next_permutation(s.begin(), s.end()));

  int count = 0;
  unordered_set<int> seen;

  for (auto it = all.begin(); it != all.end(); it++) {
    int pos = stoi(*it);
    if (seen.find(pos) == seen.end()) {
        if (IsPrime(pos)) {
        seen.insert(pos);
        count++;
      }
    }
  }

  return count;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    string num;
    cin >> num;
    cout << Solve(num) << endl;
  }

  return 0;
}