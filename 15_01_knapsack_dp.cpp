#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
  vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int w = 0; w <= W; w++) {
      if (wt[i - 1] <= w)
        dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
      else
        dp[i][w] = dp[i - 1][w];
    }
  }

  cout << "Items selected (weight, value): ";
  int w = W;
  for (int i = n; i > 0 && w > 0; i--) {
    if (dp[i][w] != dp[i - 1][w]) {
      cout << "(" << wt[i - 1] << ", " << val[i - 1] << ") ";
      w -= wt[i - 1];
    }
  }
  cout << endl;
  return dp[n][W];
}

int main() {
  int n, W;
  cout << "Enter number of items: ";
  cin >> n;
  vector<int> wt(n), val(n);
  cout << "Enter weight and value of each item: ";
  for (int i = 0; i < n; i++) cin >> wt[i] >> val[i];
  cout << "Enter capacity of knapsack: ";
  cin >> W;

  int result = knapsack(W, wt, val, n);
  cout << "Maximum value in knapsack: " << result << endl;
  cout << "This program is executed by Samridh Chaudhary (Roll No: 2400320100976)" << endl;
  return 0;
}
