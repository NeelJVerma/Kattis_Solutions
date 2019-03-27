#include <iostream>
#include <string>
using namespace std;

int Gcd(int n, int d) {
  if (!n) {
    return d;
  }

  return Gcd(d % n, n);
}

void Convert(int n, int d) {
  n = n - (d * 32);
  d *= 9;
  n *= 5;
  int gcd = Gcd(n, d);
  n /= gcd;
  d /= gcd;

  if (d < 0) {
    n = -n;
    d = -d;
  }

  cout << n << '/' << d << endl;
}

int main() {
  string t;
  cin >> t;
  int s = t.find('/');
  int n = stoi(t.substr(0, s));
  int d = stoi(t.substr(s + 1));
  Convert(n, d);

  return 0;
}