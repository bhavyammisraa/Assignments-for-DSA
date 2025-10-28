#include <iostream>
#include <vector>
#include <algorithm> // for find()
using namespace std;

// ---------------------------------------------------
// Node structure
// ---------------------------------------------------
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// ---------------------------------------------------
// Helper function to create a new node
// ---------------------------------------------------
Node *newNode(int val)
{
    return new Node(val);
}

// ---------------------------------------------------
// Function to build tree from preorder & inorder
// ---------------------------------------------------
Node *buildTree(vector<int> &preorder, vector<int> &inorder, int inStart, int inEnd, int &preIndex)
{
    if (inStart > inEnd)
        return nullptr;

    // Pick current node from preorder
    Node *root = newNode(preorder[preIndex++]);

    // If node has no children
    if (inStart == inEnd)
        return root;

    // Find index of root in inorder
    int inIndex = find(inorder.begin() + inStart, inorder.begin() + inEnd + 1, root->data) - inorder.begin();

    // Build left and right subtrees
    root->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

// ---------------------------------------------------
// Function to print inorder traversal (for verification)
// ---------------------------------------------------
void printInorder(Node *root)
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// ---------------------------------------------------
// Function to print preorder traversal (for verification)
// ---------------------------------------------------
void printPreorder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// ---------------------------------------------------
// Main function
// ---------------------------------------------------
int main()
{
    // Example input
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    int preIndex = 0;

    // Build tree
    Node *root = buildTree(preorder, inorder, 0, inorder.size() - 1, preIndex);

    // Verify the tree
    cout << "Inorder Traversal of Constructed Tree: ";
    printInorder(root);
    cout << endl;

    cout << "Preorder Traversal of Constructed Tree: ";
    printPreorder(root);
    cout << endl;

    return 0;
}
