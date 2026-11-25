// N-Queen Problem using Backtracking
// Name: Samridh Chaudhary
// Roll No: 2400320100976

#include <bits/stdc++.h>
using namespace std;

int solCount = 0;

bool isSafe(vector<int>& board, int row, int col) {
  for (int i = 0; i < row; i++) {
    if (board[i] == col || abs(board[i] - col) == abs(i - row))
      return false;
  }
  return true;
}

void printBoard(vector<int>& board, int n) {
  solCount++;
  cout << "Solution " << solCount << ":\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i] == j) cout << "Q ";
      else cout << ". ";
    }
    cout << endl;
  }
  cout << endl;
}

void solve(int row, int n, vector<int>& board) {
  if (row == n) {
    printBoard(board, n);
    return;
  }
  for (int col = 0; col < n; col++) {
    if (isSafe(board, row, col)) {
      board[row] = col;
      solve(row + 1, n, board);
    }
  }
}

int main() {
  cout << "Name: Samridh Chaudhary\n";
  cout << "Roll No: 2400320100976\n\n";

  int n;
  cout << "Enter value of N: ";
  cin >> n;

  vector<int> board(n, -1);
  solve(0, n, board);

  if (solCount == 0) cout << "No solution exists.\n";
  else cout << "Total solutions = " << solCount << endl;

  return 0;
}
