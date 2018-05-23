#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string message;
    cin >> message;

    int size = sqrt(message.length());
    char matrix[size][size];
    int letter = 0;

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        matrix[i][j] = message[letter];

        letter++;
      }
    }

    for (int i = 0; i < size / 2; i++) {
      for (int j = i; j < size - i - 1; j++) {
        char temp = matrix[i][j];
        matrix[i][j] = matrix[j][size - 1 - i];
        matrix[j][size - 1 - i] = matrix[size - 1 - i][size - 1 - j];
        matrix[size - 1 - i][size - 1 - j] = matrix[size - 1 - j][i];
        matrix[size - 1 - j][i] = temp;
      }
    }

    string decoded = "";

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        decoded += matrix[i][j];
      }
    }

    cout << decoded << endl;
  }

  return 0;
}