#include <iostream>
using namespace std;

void addMatrices(int rows, int cols, int mat1[][100], int mat2[][100], int result[][100])
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int rows, int cols, int mat1[][100], int mat2[][100], int result[][100])
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void printMatrix(int rows, int cols, int mat[][100])
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int rows, cols;

    // Input matrix dimensions
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    int mat1[100][100], mat2[100][100], result[100][100];

    // Input first matrix
    cout << "Enter elements of the first matrix:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> mat1[i][j];
        }
    }

    // Input second matrix
    cout << "Enter elements of the second matrix:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> mat2[i][j];
        }
    }

    // Add matrices
    addMatrices(rows, cols, mat1, mat2, result);
    cout << "Result of addition:" << endl;
    printMatrix(rows, cols, result);

    // Subtract matrices
    subtractMatrices(rows, cols, mat1, mat2, result);
    cout << "Result of subtraction:" << endl;
    printMatrix(rows, cols, result);

    return 0;
}
