#include <iostream>
#include <string>
using namespace std;

#define ll long long

void FindNumInTree(ll p, ll q, string& position) {
  if (p == 1 && q == 1) {
    position += '1';

    return;
  }

  if (p > q) {
    FindNumInTree(p - q, q, position);
    position += '1';
  } else {
    FindNumInTree(p, q - p, position);
    position += '0';
  }
}

int ToInt(string position) {
  ll result = 0;
  ll base = 1;

  for (int i = position.length() - 1; i >= 0; i--) {
    if (position[i] == '1') {
      result += base;
    }

    base <<= 1;
  }

  return result;
}

int main() {
  int test;
  cin >> test;
  cin.ignore();

  for (int i = 0; i < test; i++) {
    int test_num;
    string fraction;
    cin >> test_num >> fraction;

    int pos = fraction.find('/');
    ll p = stoi(fraction.substr(0, pos));
    ll q = stoi(fraction.substr(pos + 1, fraction.length()));
    string position = "";

    FindNumInTree(p, q, position);

    cout << i + 1 << ' ' << ToInt(position) << endl;
  }

  return 0;
}