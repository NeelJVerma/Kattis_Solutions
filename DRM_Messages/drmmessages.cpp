#include <iostream>
#include <string>
using namespace std;

char RotateCharacter(char c, int rotate_value) {
  return char('A' + (((c - 'A') + rotate_value) % 26));
}

void RotateString(string& s, int rotate_value) {
  for (int i = 0; i < s.length(); i++) {
    s[i] = RotateCharacter(s[i], rotate_value);
  }
}

int main() {
  string message;
  cin >> message;

  int cutoff = message.length() / 2;
  string first_half = message.substr(0, cutoff);
  string second_half = message.substr(cutoff, message.length());

  int first_r_value = 0;
  int second_r_value = 0;

  for (char c : first_half) {
    first_r_value += int(c) - 'A';
  }

  for (char c : second_half) {
    second_r_value += int(c) - 'A';
  }

  RotateString(first_half, first_r_value);
  RotateString(second_half, second_r_value);

  for (int i = 0; i < first_half.length(); i++) {
    first_half[i] = RotateCharacter(first_half[i], second_half[i] - 'A');
  }

  cout << first_half << endl;

  return 0;
}