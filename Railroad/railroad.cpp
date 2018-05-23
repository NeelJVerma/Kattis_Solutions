#include <iostream>
using namespace std;

int main() {
  int junctions, switches;
  cin >> junctions >> switches;

  cout << (switches & 1 ? "Impossible" : "Possible") << endl;
  return 0;
}