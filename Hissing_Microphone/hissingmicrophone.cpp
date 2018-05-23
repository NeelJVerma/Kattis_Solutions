#include <iostream>
#include <string>
using namespace std;

int main() {
  string word;
  cin >> word;
  
  bool hiss = false;

  for (int i = 0; i < word.length() - 1; i++) {
    if (word[i] == 's' && word[i + 1] == 's') {
      hiss = true;
    }
  }

  if (hiss) {
    cout << "hiss" << endl;
  } else {
    cout << "no hiss" << endl;
  }

  return 0;
}