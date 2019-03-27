#include <iostream>
using namespace std;

int GetTerm(int* p1, int* p2, int t) {
  int s = 0;

  for (int i = 0; i <= t; i++) {
    s += (p1[i] * p2[t - i]);
  }

  return s;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int d1, d2;
    cin >> d1;
    int p1[1000] = {0};

    for (int i = 0; i <= d1; i++) {
      cin >> p1[i];
    }

    cin >> d2;
    int p2[1000] = {0};

    for (int i = 0; i <= d2; i++) {
      cin >> p2[i];
    }

    int fd = d1 + d2;
    cout << fd << endl;

    for (int i = 0; i <= fd; i++) {
      cout << GetTerm(p1, p2, i) << ' ';
    }

    cout << endl;
  }

  return 0;
}