#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

const double kStepLength = 6.731984257692413;

int CharToInt(char c) {
  if (c == ' ') {
    return 26;
  }

  if (c == '\'') {
    return 27;
  }

  return c - 'A';
}

int ShortestRoute(char one, char two) {
  if (one == two) {
    return 0;
  }

  int int_one = CharToInt(one);
  int int_two = CharToInt(two);

  if (int_one > int_two) {
    int_one ^= int_two;
    int_two ^= int_one;
    int_one ^= int_two;
  }

  return min(int_two - int_one, 28 - int_two + int_one);
}

int SimulateRun(string aphormism) {
  int run_length = 0;

  for (int i = 0; i < aphormism.length() - 1; i++) {
    run_length += ShortestRoute(aphormism[i], aphormism[i + 1]);
  }

  return run_length;
}

int main() {
  int t;
  cin >> t;
  cin.ignore();

  while (t--) {
    string aphormism;
    getline(cin, aphormism);

    cout << fixed << setprecision(8) <<
    SimulateRun(aphormism) * kStepLength / 15 + aphormism.length() << endl;
  }

  return 0;
}