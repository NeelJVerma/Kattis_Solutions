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
#define PRARR(arr, size) for (int i = 0; i < size; i++) cout << arr[i] << ' '
#define PRV(v) for (auto i : v) cout << i << ' '
#define MEM(a, b) memset(a, (b), sizeof(a))
#define ALL(cont) cont.begin(), cont.end()
#define RALL(cont) cont.end(), cont.begin()
#define ALLARR(arr, size) arr, arr + size
#define RALLARR(arr, size) arr, arr + size, greater<int>()
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

const int kMod = 1001113;
const int kMaxN = 105;
const int kMaxV = 105;
LL arr[kMaxN][kMaxV];

void Precompute() {
  MEM(arr, 0);

  for(int i = 1; i < kMaxN; i++) {
    for (int j = 0; j < kMaxV; j++) {
      if (j == 0 || j == i - 1) {
        arr[i][j] = 1;
        continue;
      }

      arr[i][j] = ((j + 1) * arr[i - 1][j] + (i - j) * arr[i - 1][j - 1]) % kMod;
    }
  }
}

int main() {
  int t;
  SCD(t);
  Precompute();

  while (t--) {
    int k, n, v;
    SCD(k);
    SCD(n);
    SCD(v);
    printf("%d ", k);
    PRD(arr[n][v]);
  }
  
  return 0;
}