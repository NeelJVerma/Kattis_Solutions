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
#define PRLLD(t) printf("%lld\n", t)
#define PRS(t) printf("%s\n", t)
#define PRARR(arr, size) for (int i = 0; i < size; i++) cout << arr[i] << ' '
#define PRV(v) for (auto i : v) cout << i << ' '
#define MEM(a, b) memset(a, (b), sizeof(a))
#define ALL(cont) cont.begin(), cont.end()
#define RALL(cont) cont.end(), cont.begin()
#define ALLARR(arr, size) arr, arr + size
#define RALLARR(arr, size) arr, arr + size, greater<int>()
#define MP make_pair
#define PB push_back
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
const LL kInf = (int)1e9;
const double kPi = 3.1415926535897932384626433832795;
const int kMod = 1000000007;

const int kMax = 14;
const int kMaxS = 29;
int s[kMaxS][kMaxS][kMax];


int Solve(int x, int y, int n) {
  if (!n) {
    if (!x && !y) {
      return 1;
    }

    return 0;
  }

  if (s[x + kMax][y + kMax][n] != -1) {
    return s[x + kMax][y + kMax][n];
  }

  int o = 0;

  o += Solve(x - 1, y - 1, n - 1);
  o += Solve(x, y - 1, n - 1);
  o += Solve(x - 1, y, n - 1);
  o += Solve(x + 1, y + 1, n - 1);
  o += Solve(x + 1, y, n - 1);
  o += Solve(x, y + 1, n - 1);
  s[x + kMax][y + kMax][n] = o;

  return o;
}

int main() {
  MEM(s, -1);

  int t;
  SCD(t);

  while (t--) {
    int n;
    SCD(n);
    PRD(Solve(0, 0, n));
  }

  return 0;
}