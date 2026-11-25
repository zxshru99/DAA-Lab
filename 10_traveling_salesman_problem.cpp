// Traveling Salesman Problem (DP + Bitmask)
// Name: Samridh Chaudhary
// Roll No: 2400320100976

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
  cout << "Name: Samridh Chaudhary\n";
  cout << "Roll No: 2400320100976\n\n";

  int n;
  cout << "Enter number of cities: ";
  cin >> n;

  vector<vector<int>> cost(n, vector<int>(n));
  cout << "Enter cost matrix (0 or -1 for no direct path):\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> cost[i][j];
      if (i != j && cost[i][j] <= 0) cost[i][j] = INF;
    }
  }

  int total = 1 << n;
  vector<vector<int>> dp(total, vector<int>(n, INF));
  vector<vector<int>> parent(total, vector<int>(n, -1));
  dp[1][0] = 0;

  for (int mask = 1; mask < total; mask++) {
    if (!(mask & 1)) continue;
    for (int u = 0; u < n; u++) {
      if (!(mask & (1 << u)) || dp[mask][u] >= INF) continue;
      for (int v = 0; v < n; v++) {
        if ((mask & (1 << v)) || cost[u][v] >= INF) continue;
        int nmask = mask | (1 << v);
        if (dp[mask][u] + cost[u][v] < dp[nmask][v]) {
          dp[nmask][v] = dp[mask][u] + cost[u][v];
          parent[nmask][v] = u;
        }
      }
    }
  }

  int full = total - 1, best = INF, last = -1;
  for (int u = 1; u < n; u++) {
    if (dp[full][u] + cost[u][0] < best) {
      best = dp[full][u] + cost[u][0];
      last = u;
    }
  }

  if (best >= INF) {
    cout << "No valid tour exists.\n";
    return 0;
  }

  vector<int> path;
  int mask = full, cur = last;
  while (cur != -1) {
    path.push_back(cur);
    int p = parent[mask][cur];
    mask ^= (1 << cur);
    cur = p;
  }
  reverse(path.begin(), path.end());
  path.push_back(0);

  cout << "Minimum tour cost: " << best << endl;
  cout << "Tour: ";
  for (int i = 0; i < (int)path.size(); i++) {
    if (i > 0) cout << " -> ";
    cout << path[i];
  }
  cout << endl;

  return 0;
}
