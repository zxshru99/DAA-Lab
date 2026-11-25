#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void primMST(vector<vector<int>>& graph, int V) {
  vector<int> parent(V, -1);
  vector<int> key(V, INT_MAX);
  vector<bool> inMST(V, false);
  key[0] = 0;

  for (int count = 0; count < V - 1; count++) {
    int u = -1, minKey = INT_MAX;
    for (int v = 0; v < V; v++) {
      if (!inMST[v] && key[v] < minKey) {
        minKey = key[v];
        u = v;
      }
    }
    if (u == -1) break;
    inMST[u] = true;

    for (int v = 0; v < V; v++) {
      if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
        parent[v] = u;
        key[v] = graph[u][v];
      }
    }
  }

  int totalCost = 0;
  cout << "Edges in the Minimum Spanning Tree:" << endl;
  for (int i = 1; i < V; i++) {
    if (parent[i] == -1) continue;
    cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
    totalCost += graph[i][parent[i]];
  }
  cout << "Minimum cost of spanning tree: " << totalCost << endl;
}

int main() {
  int V;
  cout << "Enter number of vertices: ";
  cin >> V;
  vector<vector<int>> graph(V, vector<int>(V));
  cout << "Enter adjacency matrix (0 for no edge):\n";
  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      cin >> graph[i][j];

  primMST(graph, V);
  cout << "This program is executed by Samridh Chaudhary (Roll No: 2400320100976)" << endl;
  return 0;
}
