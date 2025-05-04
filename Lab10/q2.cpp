#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int row, int col, vector<bool> &leftRow,
            vector<bool> &upperDiag, vector<bool> &lowerDiag, int N)
{
    return !leftRow[row] && !upperDiag[N - 1 + col - row] && !lowerDiag[row + col];
}
bool solveNQueens(int col, vector<int> &board, vector<bool> &leftRow,
                  vector<bool> &upperDiag, vector<bool> &lowerDiag, int N)
{
    if (col == N)
        return true;
    for (int row = 0; row < N; row++)
    {
        if (isSafe(row, col, leftRow, upperDiag, lowerDiag, N))
        {
            board[col] = row;
            leftRow[row] = upperDiag[N - 1 + col - row] = lowerDiag[row + col] = true;

            if (solveNQueens(col + 1, board, leftRow, upperDiag, lowerDiag, N))
                return true;

            // Backtrack
            leftRow[row] = upperDiag[N - 1 + col - row] = lowerDiag[row + col] = false;
        }
    }
    return false;
}
void nQueens(int N)
{
    vector<int> board(N, -1); // board[col] = row index
    vector<bool> leftRow(N, false);
    vector<bool> upperDiag(2 * N - 1, false);
    vector<bool> lowerDiag(2 * N - 1, false);
    if (solveNQueens(0, board, leftRow, upperDiag, lowerDiag, N))
    {
        cout << "One possible solution: [";
        for (int i = 0; i < N; i++)
        {
            cout << board[i];
            if (i != N - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    else
    {
        cout << "No solution exists for N = " << N << endl;
    }
}
int main()
{
    int N = 8;
    nQueens(N);
    return 0;
}
