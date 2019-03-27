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

int main() {
  int x;
  SCD(x);
  cin.ignore();
  string s;
  SCS(s);
  int m = 0;
  int w = 0;

  for (int i = 0; i < s.length() - 1; i++) {
    s[i] == 'M' ? m++ : w++;

    if (s[i] != s[i + 1] && abs(m - w) > x) {
      if (s[i] == 'M') {
        m--;
        w++;
      } else {
        w--;
        m++;
      }

      swap(s[i], s[i + 1]);
    } else if (abs(m - w) > x) {
      w--;
      m--;
      
      break;
    }
  }

  s[s.length() - 1] == 'M' ? m++ : w++;
  PRD(w + m);

  return 0;
}