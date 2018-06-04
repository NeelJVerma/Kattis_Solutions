#include <iostream>
#include <vector>
using namespace std;

#define pb push_back

void FillGraph(vector<vector<int>>& graph, int num_vertices) {
  for (int i = 0; i < num_vertices; i++) {
    vector<int> row;

    for (int j = 0; j < num_vertices; j++) {
      int temp;
      cin >> temp;

      row.pb(temp);
    }

    graph.pb(row);
  }
}

bool HasSameNeighbor(vector<vector<int>> graph, int row_idx) {
  vector<int> row = graph[row_idx];

  for (int i = 0; i < row.size(); i++) {
    for (int j = 0; j < row.size(); j++) {
      if (i == row_idx || j == row_idx) {
        continue;
      }

      if (row[i] && graph[i][j] && graph[j][i] && graph[row_idx][j] && graph[i][row_idx]) {
        return true;
      }
    }
  }

  return false;
}

void EvaluateGraph(vector<vector<int>> graph, bool is_weak[]) {
  for (int i = 0; i < graph.size(); i++) {
    if (HasSameNeighbor(graph, i)) {
      is_weak[i] = true;
    }
  }
}

int main() {
  while (true) {
    int num_vertices;
    cin >> num_vertices;

    if (num_vertices == -1) {
      break;
    }

    vector<vector<int>> graph;
    bool is_weak[num_vertices] = { false };

    FillGraph(graph, num_vertices);
    EvaluateGraph(graph, is_weak);

    for (int i = 0; i < graph.size(); i++) {
      if (!is_weak[i]) {
        cout << i << ' ';
      }
    }
  }

  return 0;
}