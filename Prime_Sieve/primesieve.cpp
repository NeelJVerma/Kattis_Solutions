#include <iostream>
#include <unordered_set>
#include <cmath>
#include <bitset>
using namespace std;

#define ll long long

const int kMax = 100000000;
bitset<kMax> bits;

int FillSieve(int num_in) {
  bits.set();

  bits[0] = bits[1] = false;
  int num_primes = 0;

  for (ll i = 2; i <= num_in; i++) {
    if (bits[i]) {
      for (ll j = (i * i); j <= num_in; j += i) {
        bits[j] = false;
      }

      num_primes++;
    }
  }

  return num_primes;
}

int main() {
  int num_in, q;
  cin >> num_in >> q;

  cout << FillSieve(num_in) << endl;

  while (q--) {
    int tmp;
    cin >> tmp;

    cout << (bits[tmp] ? 1: 0) << endl;
  }

  return 0;
}