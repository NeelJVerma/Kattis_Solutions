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

bool Compare(string s, string t) {
  if (s[0] == t[0]) {
    return s[1] < t[1];
  }

  return s[0] < t[0];
}

int main() {
  while (true) {
    int n;
    SCD(n);
    cin.ignore();

    if (!n) {
      break;
    }

    V<string> v;

    while (n--) {
      string s;
      SCS(s);
      v.PB(s);
    }

    stable_sort(ALL(v), Compare);

    for (string s : v) {
      cout << s << endl;
    }

    cout << endl;
  }

  return 0;
}