#include <iostream>
using namespace std;

int CeilIndex(int* arr, int* arr_2, int l, int r, int key) {
  while (r - l > 1) {
    int m = l + (r - l) / 2;

    if (arr[arr_2[m]] >= key) {
      r = m;
    } else {
      l = m;
    }
  }

  return r;
}

void FillArray(int* arr, int size, int num) {
  for (int i = 0; i < size; i++) {
    arr[i] = num;
  }
}

void ReverseArray(int* arr, int size) {
  int start = 0;
  int end = size - 1;

  while (start < end) {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}

void LongestIncreasingSubsequence(int* arr, int size) {
  int length = 1;
  int* tail_index = new int[size];
  FillArray(tail_index, size, 0);
  int* prev_index = new int[size];
  FillArray(prev_index, size, -1);

  for (int i = 1; i < size; i++) {
    if (arr[i] < arr[tail_index[0]]) {
      tail_index[0] = i;
    } else if (arr[i] > arr[tail_index[length - 1]]) {
      prev_index[i] = tail_index[length - 1];
      tail_index[length++] = i;
    } else {
      int index = CeilIndex(arr, tail_index, -1, length - 1, arr[i]);
      prev_index[i] = tail_index[index - 1];
      tail_index[index] = i;
    }
  }

  cout << length << endl;
  int* index = new int[length];
  int j = 0;

  for (int i = tail_index[length - 1]; i >= 0; i = prev_index[i]) {
    index[j++] = i;
  }

  ReverseArray(index, length);

  for (int i = 0; i < length; i++) {
    cout << index[i] << ' ';
  }

  cout << endl;
}

int main() {
  int n;

  while (cin >> n) {
    int arr[n];

    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    LongestIncreasingSubsequence(arr, n);
  }

  return 0;
}