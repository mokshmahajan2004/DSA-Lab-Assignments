#include <iostream>
using namespace std;

// Triangle
void triangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++)
            cout << "*";
        cout << endl;
    }
}

// Flipped Simple Triangle
void flippedSimpleTriangle(int n)
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n - i; j++)
            cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++)
            cout << "*";
        cout << endl;
    }
}

// Inverted Pyramid
void invertedPyramid(int n)
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
            cout << "*";
        cout << endl;
    }
}

// Flipped Inverted Pyramid
void flippedInvertedPyramid(int n)
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n - i; j++)
            cout << " ";
        for (int j = 1; j <= i; j++)
            cout << "*";
        cout << endl;
    }
}

// Simple Pyramid
void simplePyramid(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << "*";
        cout << endl;
    }
}

// Half Diamond Pattern
void halfDiamondPattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << "*";
        cout << endl;
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
            cout << "*";
        cout << endl;
    }
}

// Diamond Pattern
void diamondPattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++)
            cout << "*";
        cout << endl;
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= n - i; j++)
            cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++)
            cout << "*";
        cout << endl;
    }
}

// Number Pyramid
void numberPyramid(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << i << " ";
        cout << endl;
    }
}

// Rotated Number Pyramid
void rotatedNumberPyramid(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            cout << " ";
        for (int j = 1; j <= i; j++)
            cout << j << " ";
        cout << endl;
    }
}

// Palindrome Triangle
void palindromeTriangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            cout << " ";
        for (int j = 1; j <= i; j++)
            cout << j;
        for (int j = i - 1; j >= 1; j--)
            cout << j;
        cout << endl;
    }
}

// Alphabet Pyramid
void alphabetPyramid(int n)
{
    char ch = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << ch++ << " ";
        cout << endl;
    }
}

// Continuous Alphabet Pyramid
void continuousAlphabetPyramid(int n)
{
    char ch = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << ch++ << " ";
            if (ch > 'Z')
                ch = 'A';
        }
        cout << endl;
    }
}

int main()
{
    int n = 5; // You can change this value for different sizes
    cout << "Simple Pyramid:\n";
    simplePyramid(n);

    cout << "\nFlipped Simple Triangle:\n";
    flippedSimpleTriangle(n);

    cout << "\nInverted Pyramid:\n";
    invertedPyramid(n);

    cout << "\nFlipped Inverted Pyramid:\n";
    flippedInvertedPyramid(n);

    cout << "\nTriangle:\n";
    triangle(n);

    cout << "\nHalf Diamond Pattern:\n";
    halfDiamondPattern(n);

    cout << "\nDiamond Pattern:\n";
    diamondPattern(n);

    cout << "\nNumber Pyramid:\n";
    numberPyramid(n);

    cout << "\nRotated Number Pyramid:\n";
    rotatedNumberPyramid(n);

    cout << "\nPalindrome Triangle:\n";
    palindromeTriangle(n);

    cout << "\nAlphabet Pyramid:\n";
    alphabetPyramid(n);

    cout << "\nContinuous Alphabet Pyramid:\n";
    continuousAlphabetPyramid(n);

    return 0;
}
