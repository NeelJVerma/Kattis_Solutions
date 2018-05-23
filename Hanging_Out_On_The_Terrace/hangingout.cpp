#include <iostream>
#include <string>
using namespace std;

int main() {
  int limit, num_events;
  cin >> limit >> num_events;
  cin.ignore();

  int not_allowed = 0;
  int people = 0;

  while (num_events--) {
    string event;
    getline(cin, event);

    int cutoff = event.find(' ');
    string action = event.substr(0, cutoff);
    int group_size = stoi(event.substr(cutoff, event.length()));

    if (action == "enter") {
      people += group_size;
    } else {
      people -= group_size;
    }

    if (people > limit) {
      people -= group_size;
      not_allowed++;
    }
  }

  cout << not_allowed << endl;
  return 0;
}