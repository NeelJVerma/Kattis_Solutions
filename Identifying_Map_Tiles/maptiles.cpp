#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
  string quadkey;
  cin >> quadkey;

  int zoom_level = quadkey.length();
  int x = 0;
  int y = 0;

  for (int i = 0; i < zoom_level; i++) {
    char num = quadkey[zoom_level - i - 1];

    if (num == '1') {
      x += int(pow(2, i + 1) / 2);
    } else if (num == '2') {
      y += int(pow(2, i + 1) / 2);
    } else if (num == '3') {
      x += int(pow(2, i + 1) / 2);
      y += int(pow(2, i + 1) / 2);
    }
  }

  cout << zoom_level << ' ' << x << ' ' << y << endl;

  return 0;
}