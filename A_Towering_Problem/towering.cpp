#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define pb push_back

vector<int> GetFirstTower(int* heights, int tower_one_height) {
  vector<int> first_tower;
  sort(heights, heights + 6);

  for (int i = 0; i < 4; i++) {
    int left = i + 1;
    int right = 5;

    while (left < right) {
      int sum = heights[i] + heights[left] + heights[right];
      if (sum == tower_one_height) {
        first_tower.pb(i);
        first_tower.pb(left);
        first_tower.pb(right);

        left++;
        right--;
      } else if (sum < tower_one_height) {
        left++;
      } else {
        right--;
      }
    }
  }

  return first_tower;
}

vector<int> GetSecondTower(int* heights, vector<int> first_tower) {
  vector<int> second_tower;

  for (int i = 0; i < 6; i++) {
    if (find(first_tower.begin(), first_tower.end(), i) == first_tower.end()) {
      second_tower.pb(i);
    }
  }

  return second_tower;
}

int main() {
  int heights[6];

  for (int i = 0; i < 6; i++) {
    cin >> heights[i];
  }

  int tower_one_height, tower_two_height;
  cin >> tower_one_height >> tower_two_height;

  vector<int> first_tower_idxs = GetFirstTower(heights, tower_one_height);
  vector<int> second_tower_idxs = GetSecondTower(heights, first_tower_idxs);
  vector<int> first_tower;
  vector<int> second_tower;

  for (int i = 0; i < 3; i++) {
    first_tower.pb(heights[first_tower_idxs[i]]);
    second_tower.pb(heights[second_tower_idxs[i]]);
  }

  sort(first_tower.begin(), first_tower.end(), greater<>());
  sort(second_tower.begin(), second_tower.end(), greater<>());

  for (int i = 0; i < 3; i++) {
    cout << first_tower[i] << ' ';
  }

  for (int i = 0; i < 3; i++) {
    cout << second_tower[i] << ' ';
  }

  cout << endl;

  return 0;
}