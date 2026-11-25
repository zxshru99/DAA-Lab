#include <iostream>
#include <vector>
using namespace std;

int V;
vector<vector<int>> graph;
vector<int> path;
int cycleCount = 0;

bool isSafe(int v, int pos) {
  if (graph[path[pos - 1]][v] == 0)
    return false;
  for (int i = 0; i < pos; i++)
    if (path[i] == v)
      return false;
  return true;
}

void hamCycle(int pos) {
  if (pos == V) {
    if (graph[path[pos - 1]][path[0]] == 1) {
      cycleCount++;
      for (int i = 0; i < V; i++) cout << path[i] << " ";
      cout << path[0] << endl;
    }
    return;
  }
  for (int v = 1; v < V; v++) {
    if (isSafe(v, pos)) {
      path[pos] = v;
      hamCycle(pos + 1);
      path[pos] = -1; // backtrack
    }
  }
}

int main() {
  cout << "Enter number of vertices: ";
  cin >> V;
  graph.assign(V, vector<int>(V));
  cout << "Enter adjacency matrix:\n";
  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      cin >> graph[i][j];

  path.assign(V, -1);
  path[0] = 0;

  cout << "Hamiltonian cycles:" << endl;
  hamCycle(1);
  if (cycleCount == 0)
    cout << "No Hamiltonian cycle exists" << endl;
  cout << "This program is executed by Samridh Chaudhary (Roll No: 2400320100976)" << endl;
  return 0;
}
