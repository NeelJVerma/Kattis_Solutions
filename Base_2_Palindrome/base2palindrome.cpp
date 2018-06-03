#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

const int kMaxM = 50000;
unordered_set<ll> palindromes;

ll ToInt(string palindrome) {
  ll result = 0;
  ll base = 1;

  for (int i = palindrome.length() - 1; i >= 0; i--) {
    if (palindrome[i] == '1') {
      result += base;
    }

    base <<= 1;
  }

  return result;
}

string ToBinary(ll num) {
  string result = "";

  while (num) {
    result += to_string(num % 2);
    num >>= 1;
  }

  return result;
}

ll AddFirst(int num) {
  string binary, rev;
  binary = rev = ToBinary(num);
  reverse(binary.begin(), binary.end());
  string ret = binary + rev;

  return ToInt(ret);
}

ll AddSecond(int num) {
  string binary, rev;
  binary = rev = ToBinary(num);
  reverse(binary.begin(), binary.end());
  string ret = binary + '0' + rev;

  return ToInt(ret);
}

ll AddThird(int num) {
  string binary, rev;
  binary = rev = ToBinary(num);
  reverse(binary.begin(), binary.end());
  string ret = binary + '1' + rev;

  return ToInt(ret);
}

void FillPalindromes() {
  for (int i = 0; i < kMaxM; i++) {
    palindromes.insert(AddFirst(i));
    palindromes.insert(AddSecond(i));
    palindromes.insert(AddThird(i));
  }
}

int main() {
  int m;
  cin >> m;

  FillPalindromes();
  
  vector<ll> v_palindromes(palindromes.begin(), palindromes.end());
  sort(v_palindromes.begin(), v_palindromes.end());

  int ptr = 0;

  for (int i = 0; i < v_palindromes.size(); i++) {
    if (v_palindromes[i] > 0) {
      ptr = i;

      break;
    }
  }

  cout << v_palindromes[m + ptr - 1] << endl;
  
  return 0;
}