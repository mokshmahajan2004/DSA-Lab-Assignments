#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};
// Insert a node in BST
TreeNode *insert(TreeNode *root, int key)
{
    if (!root)
        return new TreeNode(key);
    if (key < root->val)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

// Inorder Traversal (L → Root → R)
void inorder(TreeNode *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}
// Preorder Traversal (Root → L → R)
void preorder(TreeNode *root)
{
    if (root)
    {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
// Postorder Traversal (L → R → Root)
void postorder(TreeNode *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }
}
// Find minimum value node in BST
TreeNode *findMin(TreeNode *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}
// Delete a node from BST
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
        return nullptr;
    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else
    {
        // Case 1: Leaf node
        if (!root->left && !root->right)
        {
            delete root;
            return nullptr;
        }
        // Case 2: One child
        else if (!root->left)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        TreeNode *temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}
int main()
{
    // Manually inserting nodes to match the image structure
    int nodes[] = {50, 17, 72, 12, 23, 54, 76, 9, 14, 67};
    TreeNode *root = nullptr;
    for (int val : nodes)
    {
        root = insert(root, val);
    }
    cout << "\nBST Traversals:\n";
    cout << "Inorder Traversal   : ";
    inorder(root);
    cout << "\nPreorder Traversal  : ";
    preorder(root);
    cout << "\nPostorder Traversal : ";
    postorder(root);
    // Deletion
    int key;
    cout << "\n\nEnter node to delete: ";
    cin >> key;
    root = deleteNode(root, key);
    cout << "\nInorder Traversal after deletion: ";
    inorder(root);
    cout << endl;
    return 0;
}
