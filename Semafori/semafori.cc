#include <iostream>
using namespace std;

int main() {
  int num_lights, length;
  cin >> num_lights >> length;
  int time = 0, previous = 0;

  while (num_lights--) {
    int d, r, g;
    cin >> d >> r >> g;

    time += d - previous;
    int temp = time % (r + g);

    if (temp <= r) {
      time += r - temp;
    }

    previous = d;
  }

  cout << time + (length - previous) << endl;

  return 0;
}