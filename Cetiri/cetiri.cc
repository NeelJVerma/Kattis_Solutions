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

int main() {
  int arr[3];

  for (int i = 0; i < 3; i++) {
    SCD(arr[i]);
  }

  sort(ALLARR(arr, 3));

  int d = INF;

  for (int i = 1; i < 3; i++) {
    if (abs(arr[i] - arr[i - 1]) < d) {
      d = abs(arr[i] - arr[i - 1]);
    }
  }

  int num = arr[2] + d;

  for (int i = 1; i < 3; i++) {
    if (abs(arr[i] - arr[i - 1]) > d) {
      num = arr[i - 1] + d;
      break;
    }
  }

  PRD(num);
  
  return 0;
}