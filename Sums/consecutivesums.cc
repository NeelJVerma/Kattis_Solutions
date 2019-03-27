#include <iostream>
using namespace std;

int Sum(int a, int b) {
  return (b * (b + 1) - a * (a - 1)) >> 1;
}

int Check(int n, int k, int s) {
  if (Sum(s + 1, s + k) == n) {
    return s + 1;
  }

  if (Sum(s, s + k - 1) == n) {
    return s;
  }

  return 0;
}

void Solve(int n) {
  if (!(n & (n - 1))) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  int k = 2;
  int result;

  while (true) {
    result = Check(n, k, n / k - (k >> 1));

    if (result) {
      break;
    }

    k++;
  }

  cout << n << " = " << result;

  for (int i = 1; i < k; i++) {
    cout << " + " << result + i;
  }

  cout << endl;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    Solve(n);
  }

  return 0;
}