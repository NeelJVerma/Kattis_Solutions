#include <iostream>
using namespace std;

const int kMaxN = 12;

int CountIslands(int stream[kMaxN]) {
  int num_islands = 0;
  int ptr = 0;

  for (int i = ptr; i < kMaxN; i++) {
    int min = stream[ptr + 1];

    for (int j = i + 1; j < kMaxN - 1; j++) {
      if (stream[j] < min) {
        min = stream[j];
      }

      if (min > stream[ptr] && min > stream[j + 1]) {
        num_islands++;
      }
    }

    ptr++;
  }

  return num_islands;
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    int test_num, stream[kMaxN];
    cin >> test_num;

    for (int i = 0; i < kMaxN; i++) {
      cin >> stream[i];
    }

    cout << test_num << ' ' << CountIslands(stream) << endl;
  }

  return 0;
}