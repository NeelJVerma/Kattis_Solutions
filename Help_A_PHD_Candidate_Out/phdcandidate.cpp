#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string problem;
    cin >> problem;

    if (problem == "P=NP") {
      cout << "skipped" << endl;
    } else {
      int cutoff = problem.find('+');
      int num_one = stoi(problem.substr(0, cutoff));
      int num_two = stoi(problem.substr(cutoff, problem.length()));

      cout << num_one + num_two << endl;
    }
  }
  return 0;
}