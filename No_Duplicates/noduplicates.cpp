#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <sstream>
#include <iterator>
using namespace std;

int main() {
  string input;
  getline(cin, input);

  stringstream ss(input);
  istream_iterator<string> begin(ss);
  istream_iterator<string> end;
  vector<string> v_input(begin, end);

  unordered_set<string> set;
  bool no_dups = true;

  for (string s : v_input) {
    if (set.find(s) != set.end()) {
      no_dups = false;
    }

    set.insert(s);
  }

  if (no_dups) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }

  return 0;
}