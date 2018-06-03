#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int days(int* trees, int num_trees) {
  priority_queue<int> queue;

  for (int i = 0; i < num_trees; i++) {
    queue.push(trees[i]);
  }

  int day = 1, max_days = 0;

  while (!queue.empty()) {
    max_days = max(queue.top() + day, max_days);
    day++;

    queue.pop();
  }

  return max_days + 1;
}

int main() {
  int num_trees;
  cin >> num_trees;

  int* trees = new int[num_trees];

  for (int i = 0; i < num_trees; i++) {
    cin >> trees[i];
  }

  cout << days(trees, num_trees) << endl;
  return 0;
}