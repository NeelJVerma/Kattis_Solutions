#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define pb push_back

bool IsConsistent(vector<string> numbers) {
  for (int i = 1; i < numbers.size(); i++) {
    string number_1 = numbers[i - 1];
    string number_2 = numbers[i];

    if (number_1.length() <= number_2.length()) {
      string sub_number = number_2.substr(0, number_1.length());

      if (sub_number == number_1) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    int num_nums;
    cin >> num_nums;

    vector<string> numbers;

    while (num_nums--) {
      string num;
      cin >> num;

      numbers.pb(num);
    }

    sort(numbers.begin(), numbers.end());

    if (IsConsistent(numbers)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}