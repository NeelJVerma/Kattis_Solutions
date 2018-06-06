#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define pb push_back

vector<int> GetDigits(ll n) {
  vector<int> digits;

  if (n == 0) {
    digits.pb(0);
    return digits;
  }

  while (n) {
    digits.pb(n % 10);
    n /= 10;
  }

  reverse(digits.begin(), digits.end());

  return digits;
}

ll VectorToInt(vector<int> digits, int idx_1, int idx_2) {
  vector<int> num;

  for (int i = idx_1; i < idx_2; i++) {
    num.pb(digits[i]);
  }

  reverse(num.begin(), num.end());

  ll place = 1;
  ll result = 0;

  for (auto& it : num) {
    result += (it * place);
    place *= 10;
  }

  return result;
}

ll CountZeros(ll n) {
  if (n == -1) {
    return 0;
  }

  vector<int> digits = GetDigits(n);
  ll num_zeros = 0;
  ll to_multiply = 10;

  for (int i = digits.size() - 2; i > 0; i--) {
    ll left = VectorToInt(digits, 0, i);
    ll right = VectorToInt(digits, i + 1, digits.size());
    ll to_add = 0;

    if (digits[i] != 0) {
      to_add += to_multiply * left;
    } else {
      to_add += to_multiply * (left - 1) + right + 1;
    }

    num_zeros += to_add;
    to_multiply *= 10;
  }

  num_zeros += (n / 10) + 1;

  return num_zeros;
}

int main() {
  while (true) {
    ll n, m;
    cin >> n >> m;

    if (n == -1 && m == -1) {
      break;
    }

    cout << CountZeros(m) - CountZeros(n - 1) << endl;
  }

  return 0;
}