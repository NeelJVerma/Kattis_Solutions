#include <iostream>
#include <cmath>
using namespace std;

const int kMaxN = 10000001;
double dp[kMaxN] = { 0 };

void FillDp() {
  for (int i = 1; i < kMaxN; i++) {
    dp[i] += log10(i) + dp[i - 1];
  }
}

int main() {
  FillDp();
  int n;

  while (cin >> n) {
    cout << int(dp[n] + 1) << endl;
  }

  return 0;
}