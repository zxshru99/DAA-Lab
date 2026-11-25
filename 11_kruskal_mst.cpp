// MCST using Kruskal's Algorithm
// Name: Samridh Chaudhary
// Roll No: 2400320100976

#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int u, v, w;
};

bool cmp(Edge a, Edge b) {
  return a.w < b.w;
}

int findParent(int x, vector<int>& parent) {
  if (parent[x] == x) return x;
  return parent[x] = findParent(parent[x], parent);
}

void unionSet(int a, int b, vector<int>& parent, vector<int>& rnk) {
  a = findParent(a, parent);
  b = findParent(b, parent);
  if (a == b) return;
  if (rnk[a] < rnk[b]) swap(a, b);
  parent[b] = a;
  if (rnk[a] == rnk[b]) rnk[a]++;
}

int main() {
  cout << "Name: Samridh Chaudhary\n";
  cout << "Roll No: 2400320100976\n\n";

  int V, E;
  cout << "Enter number of vertices and edges: ";
  cin >> V >> E;

  vector<Edge> edges(E);
  cout << "Enter edges (u v weight):\n";
  for (int i = 0; i < E; i++) {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
  }

  sort(edges.begin(), edges.end(), cmp);

  vector<int> parent(V), rnk(V, 0);
  for (int i = 0; i < V; i++) parent[i] = i;

  int mstCost = 0;
  vector<Edge> mst;

  for (int i = 0; i < E; i++) {
    int pu = findParent(edges[i].u, parent);
    int pv = findParent(edges[i].v, parent);
    if (pu != pv) {
      mst.push_back(edges[i]);
      mstCost += edges[i].w;
      unionSet(pu, pv, parent, rnk);
    }
  }

  if ((int)mst.size() < V - 1) {
    cout << "Graph is disconnected, MST not possible.\n";
    return 0;
  }

  cout << "\nEdges in MST:\n";
  for (auto e : mst) {
    cout << e.u << " - " << e.v << " : " << e.w << endl;
  }
  cout << "Total Minimum Cost = " << mstCost << endl;

  return 0;
}
