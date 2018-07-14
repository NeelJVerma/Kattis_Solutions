#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int n;
  cin >> n;
  double minutes = 0.0;
  double seconds = 0.0;

  while (n--) {
    int m, s;
    cin >> m >> s;
    minutes += m;
    seconds += (s / 60.0);
  }

  if (seconds / minutes <= 1.0) {
    cout << "measurement error" << endl;
  } else {
    cout << setprecision(10) << seconds / minutes << endl;
  }

  return 0;
}