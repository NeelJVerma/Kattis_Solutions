#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string Solve(string s) {
  stack<char> st;

  for (char c : s) {
    if (c == '<') {
      st.pop();
    } else {
      st.push(c);
    }
  }

  string ret = "";

  while (!st.empty()) {
    ret += st.top();
    st.pop();
  }

  reverse(ret.begin(), ret.end());
  return ret;
}

int main() {
  string s;
  cin >> s;
  cout << Solve(s) << endl;
  return 0;
}