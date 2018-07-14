#include <iostream>
using namespace std;

const int kMaxEnds = 1001;

int graph[kMaxEnds][kMaxEnds];
bool visited[kMaxEnds];

void ZeroOutGraph() {
  for (int i = 0; i < kMaxEnds; i++) {
    for (int j = 0; j < kMaxEnds; j++) {
      graph[i][j] = 0;
    }
  }
}

void ZeroOutVisited() {
  for (int i = 0; i < kMaxEnds; i++) {
    visited[i] = false;
  }
}

void AddEndpoint(int a, int b) {
  graph[a][b] = 1;
  graph[b][a] = 1;
}

int DFS(int v, int num_endpoints) {
  visited[v] = true;

  for (int i = graph[v][0]; i < num_endpoints; i++) {
    if (!visited[i] && graph[i][v]) {
      DFS(i, num_endpoints);
    }
  }
}

int CountComponents(int num_endpoints) {
  int count = -1;

  for (int i = 0; i < num_endpoints; i++) {
    if (!visited[i]) {
      DFS(i, num_endpoints);
      count++;
    }
  }

  return count;
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    int num_endpoints;
    cin >> num_endpoints;

    int num_pairs;
    cin >> num_pairs;

    ZeroOutGraph();
    ZeroOutVisited();

    while (num_pairs--) {
      int a, b;
      cin >> a >> b;

      AddEndpoint(a, b);
    }

    cout << CountComponents(num_endpoints) << endl;
  }

  return 0;
}