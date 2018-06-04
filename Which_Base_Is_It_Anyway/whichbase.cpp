#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int AsOctal(int num) {
  int result = 0;
  int base = 1;

  while (num) {
    if (num % 10 > 7) {
      return 0;
    }

    result += ((num % 10) * base);
    num /= 10;
    base <<= 3;
  }

  return result;
}

int AsHex(int num) {
  int result = 0;
  int base = 1;

  while (num) {
    result += ((num % 10) * base);
    num /= 10;
    base <<= 4;
  }

  return result;
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    int test_num, num;
    cin >> test_num >> num;

    cout << test_num << ' ' << AsOctal(num) << ' ' << num << ' ' << AsHex(num) << endl;
  }

  return 0;
}