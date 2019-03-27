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

M<char, int> s_map = {{'1', 1},
                      {'2', 2},
                      {'3', 3},
                      {'4', 4},
                      {'5', 5},
                      {'6', 6},
                      {'7', 7},
                      {'8', 8},
                      {'9', 9},
                      {'A', 10},
                      {'B', 8},
                      {'C', 11},
                      {'D', 12},
                      {'E', 13},
                      {'F', 14},
                      {'G', 11},
                      {'H', 15},
                      {'I', 1},
                      {'J', 16},
                      {'K', 17},
                      {'L', 18},
                      {'M', 19},
                      {'N', 20},
                      {'O', 0},
                      {'P', 21},
                      {'Q', 0},
                      {'R', 22},
                      {'S', 5},
                      {'T', 23},
                      {'U', 24},
                      {'V', 24},
                      {'W', 25},
                      {'X', 26},
                      {'Y', 24},
                      {'Z', 2}};

int factors[8] = {2, 4, 5, 7, 8, 10, 11, 13};

int Check(string s) {
  int ret = 0;

  for (int i = 0; i < 8; i++) {
    ret += (s_map[s[i]] * factors[i]);
  }

  return ret % 27;
}

ULL Convert(string s) {
  ULL exp = 0;
  ULL ret = 0;

  for (int i = s.length() - 2; i >= 0; i--) {
    ret += (s_map[s[i]] * pow(27ULL, exp));
    exp++;
  }

  return ret;
}

int main() {
  int t;
  SCD(t);

  while (t--) {
    int k;
    string s;
    SCD(k);
    cin.ignore();
    SCS(s);
    printf("%d ", k);

    if (Check(s) != s_map[s[8]]) {
      puts("Invalid");
    } else {
      PRLLD(Convert(s));
    }
  }

  return 0;
}