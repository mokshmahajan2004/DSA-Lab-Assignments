#include <iostream>
using namespace std;

void multiplyMatrices(int mat1[10][10], int mat2[10][10], int result[10][10], int size)
{
    // Initialize the result matrix with zeros
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            result[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            for (int k = 0; k < size; ++k)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void printMatrix(int mat[10][10], int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int size = 10;
    int mat1[10][10], mat2[10][10], result[10][10];

    // Input first matrix
    cout << "Enter elements of the first 10x10 matrix:" << endl;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cin >> mat1[i][j];
        }
    }

    // Input second matrix
    cout << "Enter elements of the second 10x10 matrix:" << endl;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cin >> mat2[i][j];
        }
    }

    // Multiply matrices
    multiplyMatrices(mat1, mat2, result, size);

    // Print the result matrix
    cout << "Result of matrix multiplication:" << endl;
    printMatrix(result, size);

    return 0;
}
