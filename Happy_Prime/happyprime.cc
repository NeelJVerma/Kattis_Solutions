#include <iostream>
using namespace std;

bool IsPrime(int n) {
  if (n <= 1) {
    return false;
  }

  if (n <= 3) {
    return true;
  }

  if (!(n % 2) || !(n % 3)) {
    return false;
  }

  for (int i = 5; (i * i) <= n; i += 6) {
    if (!(n % i) || !(n % (i + 2))) {
      return false;
    }
  }

  return true;
}

int SumDigits(int num) {
  int ret = 0;

  while (num) {
    ret += ((num % 10) * (num % 10));
    num /= 10;
  }

  return ret;
}

bool IsHappy(int num) {
  int its = 0;

  while (its < 10) {
    int check = SumDigits(num);

    if (check == 1) {
      return true;
    }

    num = check;
    its++;
  }

  return false;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int t_num, num;
    cin >> t_num >> num;

    if (!IsPrime(num) || num == 1) {
      cout << t_num << ' ' << num << " NO" << endl;
      continue;
    }

    if (IsHappy(num)) {
      cout << t_num << ' ' << num << " YES" << endl;
    } else {
      cout << t_num << ' ' << num << " NO" << endl;
    }
  }
  
  return 0;
}