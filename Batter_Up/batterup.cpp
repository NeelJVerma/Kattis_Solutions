#include <iostream>
using namespace std;

int main() {
  int num_at_bats;
  cin >> num_at_bats;

  float percentage = 0;
  int to_ignore = 0;

  for (int i = 0; i < num_at_bats; i++) {
    int at_bat;
    cin >> at_bat;

    if (at_bat == -1) {
      to_ignore++;

      continue;
    }

    percentage += at_bat;
  }

  percentage /= num_at_bats - to_ignore;

  cout << percentage << endl;

  return 0;
}