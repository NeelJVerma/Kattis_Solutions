#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void Solve(int n, int d) {
  if (d == 1){
    cout << "1/" << (1 + n) << endl;
    return;
  }

  if (n < d) {
    cout << d << '/' << (d - n) << endl;
    return;
  }

  int pos = n / d;
  n %= d;
  d -= n;
  n += d;
  d += (n * pos);

  cout << n << '/' << d << endl;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int tn;
    string s;
    cin >> tn;
    cin.ignore();
    getline(cin, s);
    int i = s.find('/');
    int n = stoi(s.substr(0, i));
    int d = stoi(s.substr(i + 1));
    cout << tn << ' ';
    Solve(n, d);
  }

  return 0;
}