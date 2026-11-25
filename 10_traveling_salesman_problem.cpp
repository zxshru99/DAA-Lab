/*
 * Program 10: Traveling Salesman Problem (Dynamic Programming / Held-Karp)
 * Name: Samridh Chaudhary
 * Roll No: 2400320100976
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

int main() {
    cout << "Name: Samridh Chaudhary\n";
    cout << "Roll No: 2400320100976\n";
    cout << "Program: Traveling Salesman Problem\n\n";

    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    if (n <= 0 || n > 20) {
        cout << "Please enter between 1 and 20 cities.\n";
        return 0;
    }

    vector<vector<int>> cost(n, vector<int>(n));
    cout << "Enter the " << n << "x" << n << " cost matrix (use 0 or -1 for no direct path):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
            if (i != j && cost[i][j] <= 0) {
                cost[i][j] = INF;
            }
        }
    }

    if (n == 1) {
        cout << "\nMinimum tour cost: 0\nTour: 0 -> 0\n";
        return 0;
    }

    int totalMasks = 1 << n;
    // dp[mask][u] = minimum cost to visit all cities in `mask`, ending at city `u`.
    vector<vector<int>> dp(totalMasks, vector<int>(n, INF));
    vector<vector<int>> parent(totalMasks, vector<int>(n, -1));

    dp[1][0] = 0; // Start from city 0.

    for (int mask = 1; mask < totalMasks; ++mask) {
        if ((mask & 1) == 0) {
            continue;
        }
        for (int u = 0; u < n; ++u) {
            if ((mask & (1 << u)) == 0 || dp[mask][u] >= INF) {
                continue;
            }
            for (int v = 0; v < n; ++v) {
                if ((mask & (1 << v)) != 0 || cost[u][v] >= INF) {
                    continue;
                }
                int nextMask = mask | (1 << v);
                int newCost = dp[mask][u] + cost[u][v];
                if (newCost < dp[nextMask][v]) {
                    dp[nextMask][v] = newCost;
                    parent[nextMask][v] = u;
                }
            }
        }
    }

    int fullMask = totalMasks - 1;
    int bestCost = INF;
    int lastCity = -1;

    for (int u = 1; u < n; ++u) {
        if (dp[fullMask][u] < INF && cost[u][0] < INF) {
            int tourCost = dp[fullMask][u] + cost[u][0];
            if (tourCost < bestCost) {
                bestCost = tourCost;
                lastCity = u;
            }
        }
    }

    if (bestCost >= INF) {
        cout << "\nNo valid Traveling Salesman tour exists.\n";
        return 0;
    }

    // Reconstruct the optimal tour backwards from lastCity to 0.
    vector<int> path;
    int currMask = fullMask;
    int currCity = lastCity;

    while (currCity != -1) {
        path.push_back(currCity);
        int prevCity = parent[currMask][currCity];
        currMask ^= (1 << currCity);
        currCity = prevCity;
    }
    reverse(path.begin(), path.end());
    path.push_back(0);

    cout << "\nMinimum tour cost: " << bestCost << "\n";
    cout << "Optimal tour: ";
    for (size_t i = 0; i < path.size(); ++i) {
        if (i > 0) {
            cout << " -> ";
        }
        cout << path[i];
    }
    cout << "\n";

    return 0;
}
