#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int beats;
    float seconds;
    cin >> beats >> seconds;

    double abpm = (60 * beats) / seconds;
    double interval = 60 / seconds;
    double min_bpm = abpm - interval;
    double max_bpm = abpm + interval;

    cout << fixed << setprecision(4) << min_bpm << ' '
         << fixed << setprecision(4) << abpm << ' '
         << fixed << setprecision(4) << max_bpm << endl;
  }

  return 0;
}