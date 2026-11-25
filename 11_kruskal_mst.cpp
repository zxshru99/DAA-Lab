/*
 * Program 11: Minimum Cost Spanning Tree (MCST) using Kruskal's Algorithm
 * Name: Samridh Chaudhary
 * Roll No: 2400320100976
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct Edge {
    int u;
    int v;
    int weight;
};

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    explicit DisjointSet(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression.
        }
        return parent[x];
    }

    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB) {
            return false;
        }

        if (rank[rootA] < rank[rootB]) {
            swap(rootA, rootB);
        }
        parent[rootB] = rootA;
        if (rank[rootA] == rank[rootB]) {
            ++rank[rootA];
        }
        return true;
    }
};

int main() {
    cout << "Name: Samridh Chaudhary\n";
    cout << "Roll No: 2400320100976\n";
    cout << "Program: MCST using Kruskal's Algorithm\n\n";

    int vertices, numEdges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> numEdges;

    if (vertices <= 0 || numEdges < 0) {
        cout << "Invalid graph dimensions.\n";
        return 0;
    }

    vector<Edge> edges(numEdges);
    cout << "Enter each edge as (u v weight) with 0-based vertices:\n";
    for (int i = 0; i < numEdges; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Sort edges from smallest weight to largest.
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    DisjointSet dsu(vertices);
    vector<Edge> mstEdges;
    int totalCost = 0;

    for (const Edge& e : edges) {
        if (e.u < 0 || e.u >= vertices || e.v < 0 || e.v >= vertices) {
            continue;
        }
        if (dsu.unite(e.u, e.v)) {
            mstEdges.push_back(e);
            totalCost += e.weight;
            if (static_cast<int>(mstEdges.size()) == vertices - 1) {
                break;
            }
        }
    }

    if (static_cast<int>(mstEdges.size()) < vertices - 1) {
        cout << "\nGraph is disconnected; a complete spanning tree does not exist.\n";
        return 0;
    }

    cout << "\nEdges in the Minimum Cost Spanning Tree:\n";
    for (const Edge& e : mstEdges) {
        cout << e.u << " -- " << e.v << "  (weight: " << e.weight << ")\n";
    }
    cout << "Total Minimum Cost = " << totalCost << "\n";

    return 0;
}
