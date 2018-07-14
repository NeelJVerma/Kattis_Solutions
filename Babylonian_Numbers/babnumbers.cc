#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long ull;

ull Solve(string s) {
  ull ret = 0;
  int num = 0;

  for (char c : s) {
    if (c == ',') {
      ret *= 60;
      ret += num;
      num = 0;
    } else {
      num *= 10;
      num += (c - '0');
    }
  }

  ret *= 60;
  ret += num;
  return ret;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;
    cout << Solve(s) << endl;
  }

  return 0;
}