#include <iostream>
#include <utility>
#include <bitset>
#include <vector>
#include <unordered_set>
using namespace std;

struct PairHash {
  inline int operator()(const pair<int,int>& p) const {
    return p.first * 31 + p.second;
  }
};

const int kMax = 32000;
bitset<kMax> primes;
#define pb push_back

void FillSieve() {
  primes.set();
  primes[0] = primes[1] = false;

  for (int i = 2; i <= kMax; i++) {
    if (primes[i]) {
      for (int j = (i * i); j <= kMax; j += i) {
        primes[j] = false;
      }
    }
  }
}

vector<pair<int, int>> Solve(int n) {
  vector<pair<int, int>> v;
  FillSieve();
  unordered_set<pair<int, int>, PairHash> s;

  for (int i = 2; i <= n; i++) {
    if (primes[i] && primes[n - i]) {
      pair<int, int> p;
      
      if (i < (n - i)) {
        p = make_pair<int, int>((int)i, n - i);
      } else {
        p = make_pair<int, int>(n - i, (int)i);
      }

      if (s.find(p) == s.end()) {
        v.pb(p);
      }

      s.insert(p);
    }
  }

  return v;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> v = Solve(n);
    cout << n << " has " << v.size() << " representation(s)" << endl;

    for (pair<int, int> p : v) {
      cout << p.first << '+' << p.second << endl;
    }

    cout << endl;
  }

  return 0;
}