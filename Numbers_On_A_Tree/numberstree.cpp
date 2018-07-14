#include <iostream>
#include <string>
using namespace std;

int CalculateNumInTree(int height, string sequence) {
  int num_nodes = 1 << (height + 1);
  int pos = 1;

  for (char c : sequence) {
    pos <<= 1;

    if (c == 'R') {
      pos++;
    }
  }

  return num_nodes - pos;
}

int main() {
  int height;
  string sequence;
  cin >> height >> sequence;

  cout << CalculateNumInTree(height, sequence) << endl;

  return 0;
}