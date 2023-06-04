#include <iostream>
#include <vector>

using namespace std;

// Function to check if a queen can be placed at a given position
bool isSafe(vector<vector<int>>& board, int row, int col, int n)
{
    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true; // Position is safe to place a queen
}

// Function to solve the N-Queens problem using backtracking and branch and bound
bool solveNQueens(vector<vector<int>>& board, int row, int n, int& solutions)
{
    if (row == n) {
        // All queens have been placed, a solution is found
        solutions++;
        cout << "Solution " << solutions << ":\n";

        // Print the board configuration
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
        return false; // Continue searching for more solutions
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            // Place a queen at the current position
            board[row][col] = 1;

            // Recursively solve the subproblem for the next row
            if (solveNQueens(board, row + 1, n, solutions)) {
                return true; // Solution found, terminate the search
            }

            // Backtrack and remove the queen from the current position
            board[row][col] = 0;
        }
    }

    return false; // No solution found
}

// Function to solve the N-Queens problem
void solveNQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0)); // Initialize the chessboard

    int solutions = 0; // Count of solutions

    solveNQueens(board, 0, n, solutions);

    cout << "Total solutions: " << solutions << endl;
}

int main()
{
     int N;
    cout << "Enter the number of queens (N): ";
    cin >> N;

    solveNQueens(N);
    return 0;
}
