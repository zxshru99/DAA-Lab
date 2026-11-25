#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void dijkstra(vector<vector<int>>& graph, int V, int src) {
  vector<int> dist(V, INT_MAX);
  vector<bool> visited(V, false);
  vector<int> parent(V, -1);
  dist[src] = 0;

  for (int count = 0; count < V - 1; count++) {
    int u = -1, minDist = INT_MAX;
    for (int v = 0; v < V; v++) {
      if (!visited[v] && dist[v] < minDist) {
        minDist = dist[v];
        u = v;
      }
    }
    if (u == -1) break;
    visited[u] = true;

    for (int v = 0; v < V; v++) {
      if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
        dist[v] = dist[u] + graph[u][v];
        parent[v] = u;
      }
    }
  }

  cout << "Vertex\tDistance\tPath" << endl;
  for (int i = 0; i < V; i++) {
    cout << i << "\t" << dist[i] << "\t\t";
    vector<int> path;
    for (int v = i; v != -1; v = parent[v]) path.push_back(v);
    for (int j = path.size() - 1; j >= 0; j--) {
      cout << path[j];
      if (j) cout << " -> ";
    }
    cout << endl;
  }
}

int main() {
  int V, src;
  cout << "Enter number of vertices: ";
  cin >> V;
  vector<vector<int>> graph(V, vector<int>(V));
  cout << "Enter adjacency matrix (0 for no edge):\n";
  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      cin >> graph[i][j];
  cout << "Enter source vertex: ";
  cin >> src;

  dijkstra(graph, V, src);
  cout << "This program is executed by Samridh Chaudhary (Roll No: 2400320100976)" << endl;
  return 0;
}
