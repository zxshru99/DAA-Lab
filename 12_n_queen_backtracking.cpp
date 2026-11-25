/*
 * Program 12: N-Queen Problem using Backtracking
 * Name: Samridh Chaudhary
 * Roll No: 2400320100976
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isSafe(const vector<int>& queenCol, int row, int col) {
    for (int prevRow = 0; prevRow < row; ++prevRow) {
        int prevCol = queenCol[prevRow];
        if (prevCol == col || abs(prevRow - row) == abs(prevCol - col)) {
            return false;
        }
    }
    return true;
}

void printBoard(const vector<int>& queenCol, int solutionNumber) {
    int n = static_cast<int>(queenCol.size());
    cout << "Solution " << solutionNumber << ":\n";

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cout << (queenCol[r] == c ? "Q " : ". ");
        }
        cout << "\n";
    }
    cout << "\n";
}

void solveNQueen(int row, int n, vector<int>& queenCol, int& solutionCount) {
    if (row == n) {
        ++solutionCount;
        printBoard(queenCol, solutionCount);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(queenCol, row, col)) {
            queenCol[row] = col;
            solveNQueen(row + 1, n, queenCol, solutionCount);
            queenCol[row] = -1; // Backtrack.
        }
    }
}

int main() {
    cout << "Name: Samridh Chaudhary\n";
    cout << "Roll No: 2400320100976\n";
    cout << "Program: N-Queen using Backtracking\n\n";

    int n;
    cout << "Enter board size N: ";
    cin >> n;

    if (n <= 0) {
        cout << "Board size must be positive.\n";
        return 0;
    }

    vector<int> queenCol(n, -1);
    int solutionCount = 0;

    solveNQueen(0, n, queenCol, solutionCount);

    if (solutionCount == 0) {
        cout << "No solutions exist for N = " << n << ".\n";
    } else {
        cout << "Total solutions found: " << solutionCount << "\n";
    }

    return 0;
}
