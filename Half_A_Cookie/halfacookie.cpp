#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const float PI = 3.1415926535897932384626433832795028841971693993751;

int main() {
  float radius, x_hit, y_hit;

  while (cin >> radius >> x_hit >> y_hit) {
    float distance = (x_hit * x_hit) + (y_hit * y_hit);

    if (distance >= (radius * radius)) {
      cout << "miss" << endl;
      continue;
    }

    distance = sqrt(distance);
    float h = radius - distance;
    float part_one = (radius * radius) * acos((radius - h) / radius) -
                     (radius - h) * sqrt(2 * radius * h - h * h);
    float circle_one = PI * (radius * radius);
    float left_one = circle_one - part_one;

    if (left_one < part_one) {
      cout << fixed << setprecision(7) << part_one << ' ' << setprecision(7) << left_one << endl;
    } else {
      cout << fixed << setprecision(7) << left_one << ' ' << setprecision(7) << part_one << endl;
    }
  }

  return 0;
}