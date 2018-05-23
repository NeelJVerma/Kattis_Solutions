#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
  int parts, days;
  cin >> parts >> days;

  unordered_set<string> distinct_parts;
  int last_day = -1;

  for (int i = 0; i < days; i++) {
    string part;
    cin >> part;

    distinct_parts.insert(part);

    if (distinct_parts.size() == parts) {
      last_day = i + 1;

      break;
    }
  }

  if (last_day == -1) {
    cout << "paradox avoided" << endl;
  } else {
    cout << last_day << endl;
  }

  return 0;
}