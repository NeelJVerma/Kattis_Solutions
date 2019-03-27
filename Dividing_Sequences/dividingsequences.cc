#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define SCD(t) scanf("%d", &t)
#define SCLD(t) scanf("%ld", &t)
#define SCLLD(t) scanf("%lld", &t)
#define SCC(t) scanf("%c", &t)
#define SCS(t) getline(cin, t)
#define SCF(t) scanf("%f", &t)
#define SCLF(t) scanf("%lf", &t)
#define PRD(t) printf("%d\n", t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define ALL(cont) cont.begin(), cont.end()
#define RALL(cont) cont.end(), cont.begin()
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define P pair
#define V vector
#define Q queue
#define ST stack
#define BS bitset
#define M map
#define S set
#define UM unordered_map
#define US unordered_set
#define MM multimap
#define MS multiset
typedef long L;
typedef unsigned long UL;
typedef long long LL;
typedef unsigned long long ULL;

const int kMax = 1000005;
int p[kMax];
int l[kMax];
BS<kMax> bits;
V<int> factors[kMax];

void FillSieve() {
  bits.set();
  bits[0] = bits[1] = false;

  for (int i = 2; i < kMax; i++) {
    if (bits[i]) {
      for (int j = i; j < kMax; j += i) {
        bits[j] = false;
        factors[j].PB(i);
      }
    }
  }
}

void Precompute() {
  l[1] = 1;

  for (int i = 2; i < kMax; i++) {
    for (int f : factors[i]) {
      int t = i / f;

      if (l[i] < l[t] + 1) {
        p[i] = t;
        l[i] = l[t] + 1;
      }
    }
  }
}

void Solve(int n) {
  FillSieve();
  Precompute();
  int i = 1;

  for (int j = 1; j <= n; j++) {
    if (l[i] < l[j]) {
      i = j;
    }
  }

  V<int> ans;

  while (i != 1) {
    ans.PB(i);
    i = p[i];
  }

  ans.PB(1);
  reverse(ALL(ans));

  PRD(ans.size());

  for (int j = 0; j < ans.size(); j++) {
    cout << ans[j] << ' ';
  }

  cout << endl;
}

int main() {
  int n;
  SCD(n);
  Solve(n);

  return 0;
}