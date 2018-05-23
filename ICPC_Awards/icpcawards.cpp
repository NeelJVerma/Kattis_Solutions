#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  int num_teams;
  cin >> num_teams;
  cin.ignore();

  vector<string> winners;
  unordered_set<string> teams;

  for (int i = 0; i < num_teams; i++) {
    string team_name;
    getline(cin, team_name);

    int space = team_name.find(' ');
    string school = team_name.substr(0, space);

    if (teams.find(school) == teams.end()) {
      teams.insert(school);
      winners.push_back(team_name);
    }
  }

  for (int i = 0; i < 12; i++) {
    cout << winners[i] << endl;
  }

  return 0;
}