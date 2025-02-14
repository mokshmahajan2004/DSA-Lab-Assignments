#include <iostream>
#include <stack>
#include <cctype>
using namespace std;
// Function to return precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3; // Higher precedence for exponentiation
    return 0;
}
// Function to convert infix to postfix
string infixToPostfix(const string &infix)
{
    stack<char> st;
    string postfix;
    for (char ch : infix)
    {
        // If character is an operand, add to output
        if (isalnum(ch))
        {
            postfix += ch;
        }
        // If left parenthesis, push to stack
        else if (ch == '(')
        {
            st.push(ch);
        }
        // If right parenthesis, pop until '('
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // Remove '('
        }
        // If operator, pop operators with higher precedence and push current
        else
        {
            while (!st.empty() && precedence(st.top()) >= precedence(ch))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    // Pop remaining operators from stack
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}
int main()
{
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    cout << "\nTime Complexity Analysis:\n";
    cout << "Best Case: O(n) (Well-formatted input with minimal operations)\n";
    cout << "Worst Case: O(n) (Deeply nested expressions requiring multiple stack operations)\n";
    cout << "Average Case: O(n)\n";
    return 0;
}
