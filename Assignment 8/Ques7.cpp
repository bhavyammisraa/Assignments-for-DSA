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
// Helper function to create new node
// ---------------------------------------------------
Node *newNode(int val)
{
    return new Node(val);
}

// ---------------------------------------------------
// Build tree from inorder & postorder traversals
// ---------------------------------------------------
Node *buildFromInPost(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int &postIndex)
{
    if (inStart > inEnd)
        return nullptr;

    // Pick the current node from postorder (from end)
    Node *root = newNode(postorder[postIndex--]);

    // If no children (leaf node)
    if (inStart == inEnd)
        return root;

    // Find the index of root in inorder
    int inIndex = find(inorder.begin() + inStart, inorder.begin() + inEnd + 1, root->data) - inorder.begin();

    // Build right subtree first (since postorder = Left Right Root)
    root->right = buildFromInPost(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left = buildFromInPost(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

// ---------------------------------------------------
// Print inorder traversal (for verification)
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
// Print postorder traversal (for verification)
// ---------------------------------------------------
void printPostorder(Node *root)
{
    if (!root)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

// ---------------------------------------------------
// Print preorder traversal (to verify reconstruction)
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
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    int postIndex = postorder.size() - 1;

    // Build tree
    Node *root = buildFromInPost(inorder, postorder, 0, inorder.size() - 1, postIndex);

    // Verification
    cout << "Inorder Traversal of Constructed Tree: ";
    printInorder(root);
    cout << endl;

    cout << "Postorder Traversal of Constructed Tree: ";
    printPostorder(root);
    cout << endl;

    cout << "Preorder Traversal of Constructed Tree: ";
    printPreorder(root);
    cout << endl;

    return 0;
}
