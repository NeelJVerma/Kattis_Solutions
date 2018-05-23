#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    bool possible = false;
    int one, two, three;
    cin >> one >> two >> three;

    if (one + two == three) {
      possible = true;
    } else if (one - two == three || two - one == three) {
      possible = true;
    } else if (one * two == three) {
      possible = true;
    } else if (float(one) / two == three || float(two) / one == three) {
      possible = true;
    }

    if (possible) {
      cout << "Possible" << endl;
    } else {
      cout << "Impossible" << endl;
    }
  }

  return 0;
}