#include <iostream>
#include <vector>
using namespace std;

int main() {
  int stars;
  cin >> stars;

  int most = (stars / 2) + ((stars & 1) ? 2 : 1);

  cout << stars << ':' << endl;
  
  for (int i = 2; i < most; i++) {
    int remainder = stars % ((i * 2) - 1);

    if (remainder == 0 || remainder == i) {
      cout << i << ',' << i - 1 << endl;
    }

    if (!(stars % i)) {
      cout << i << ',' << i << endl;
    }
  }

  return 0;
}