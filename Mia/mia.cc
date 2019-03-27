#include <iostream>
using namespace std;

bool IsHighestScore(int a, int b) {
  return ((a == 2 && b == 1) || (a == 1 && b == 2));
}

bool IsDouble(int a, int b) {
  return (a == b);
}

int GetScore(int a, int b) {
  if (a > b) {
    return (a * 10) + b;
  }

  return (b * 10) + a;
}

int main() {
  while (true) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (!a && !b && !c && !d) {
      break;
    }

    if (IsHighestScore(a, b) && IsHighestScore(c, d)) {
      cout << "Tie." << endl;
      continue;
    }

    if (IsHighestScore(a, b)) {
      cout << "Player 1 wins." << endl;
      continue;
    }

    if (IsHighestScore(c, d)) {
      cout << "Player 2 wins." << endl;
      continue;
    }

    if (IsDouble(a, b) && IsDouble(c, d)) {
      if (a > c) {
        cout << "Player 1 wins." << endl;
      } else if (c > a) {
        cout << "Player 2 wins." << endl;
      } else {
        cout << "Tie." << endl;
      }

      continue;
    }

    if (IsDouble(a, b)) {
      cout << "Player 1 wins." << endl;
      continue;
    }

    if (IsDouble(c, d)) {
      cout << "Player 2 wins." << endl;
      continue;
    }

    int one_score = GetScore(a, b);
    int two_score = GetScore(c, d);

    if (one_score == two_score) {
      cout << "Tie." << endl;
    } else if (one_score > two_score) {
      cout << "Player 1 wins." << endl;
    } else {
      cout << "Player 2 wins." << endl;
    }
  }

  return 0;
}