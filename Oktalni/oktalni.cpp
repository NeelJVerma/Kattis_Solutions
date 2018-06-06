#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

const unordered_map<string, char> octal({{ "000", '0' },
                                         { "001", '1' },
                                         { "010", '2' },
                                         { "011", '3' },
                                         { "100", '4' },
                                         { "101", '5' },
                                         { "110", '6' },
                                         { "111", '7' }});

string ToOctal(string binary) {
  string result = "";

  while (binary.length() % 3) {
    binary.insert(binary.begin(), '0');
  }

  for (int i = 0; i < binary.length(); i += 3) {
    string three_bits = "";
    three_bits.insert(three_bits.end(), binary[i]);
    three_bits.insert(three_bits.end(), binary[i + 1]);
    three_bits.insert(three_bits.end(), binary[i + 2]);
    auto octal_find = octal.find(three_bits);
    result += octal_find->second;
  }

  return result;
}

int main() {
  string binary;
  cin >> binary;

  cout << ToOctal(binary) << endl;
  return 0;
}