#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};
// Function to insert nodes in level order
TreeNode *insertLevelOrder(const vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

    TreeNode *root = new TreeNode(arr[0]);
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (i < arr.size())
    {
        TreeNode *curr = q.front();
        q.pop();

        if (i < arr.size())
        {
            curr->left = new TreeNode(arr[i++]);
            q.push(curr->left);
        }
        if (i < arr.size())
        {
            curr->right = new TreeNode(arr[i++]);
            q.push(curr->right);
        }
    }
    return root;
}
// Function to check height and balance
int checkBalanced(TreeNode *root, bool &isBalanced)
{
    if (!root)
        return 0;
    int leftHeight = checkBalanced(root->left, isBalanced);
    int rightHeight = checkBalanced(root->right, isBalanced);
    if (abs(leftHeight - rightHeight) > 1)
        isBalanced = false;
    return max(leftHeight, rightHeight) + 1;
}
bool isBalanced(TreeNode *root)
{
    bool result = true;
    checkBalanced(root, result);
    return result;
}
// Function to check completeness
bool isComplete(TreeNode *root)
{
    if (!root)
        return true;
    queue<TreeNode *> q;
    q.push(root);
    bool foundNull = false;
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();

        if (!curr)
        {
            foundNull = true;
        }
        else
        {
            if (foundNull)
                return false;
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return true;
}
// Function to check if tree is full
bool isFull(TreeNode *root)
{
    if (!root)
        return true;
    if (!root->left && !root->right)
        return true;
    if (root->left && root->right)
        return isFull(root->left) && isFull(root->right);
    return false;
}
// Function to calculate depth
int findDepth(TreeNode *root)
{
    int d = 0;
    while (root)
    {
        d++;
        root = root->left;
    }
    return d;
}
// Function to check if tree is perfect
bool isPerfect(TreeNode *root, int depth, int level = 0)
{
    if (!root)
        return true;
    if (!root->left && !root->right)
        return depth == level + 1;
    if (!root->left || !root->right)
        return false;
    return isPerfect(root->left, depth, level + 1) &&
           isPerfect(root->right, depth, level + 1);
}
int main()
{
    vector<int> arr;
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        arr.push_back(val);
    }
    TreeNode *root = insertLevelOrder(arr);
    cout << "\nBinary Tree Properties:\n";
    cout << "Balanced: " << (isBalanced(root) ? "Yes" : "No") << endl;
    cout << "Complete: " << (isComplete(root) ? "Yes" : "No") << endl;
    cout << "Full: " << (isFull(root) ? "Yes" : "No") << endl;
    cout << "Perfect: " << (isPerfect(root, findDepth(root)) ? "Yes" : "No") << endl;

    return 0;
}
