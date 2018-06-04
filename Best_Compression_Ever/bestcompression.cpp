#include <iostream>
using namespace std;

#define ull unsigned long long

int main() {
  ull num_files;
  int bits;
  cin >> num_files >> bits;

  cout << (num_files <= ((2LLU << bits) - 1) ? "yes": "no") << endl;
  return 0;
}