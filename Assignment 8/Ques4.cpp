#include <iostream>
using namespace std;

// Node structure
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

// Function to insert node into BST
Node *insert(Node *root, int val)
{
    if (root == nullptr)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// Function to print inorder traversal
void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// ---------------------------------------------------
// ✅ Function to check if a Binary Tree is a BST
// ---------------------------------------------------
bool isBSTUtil(Node *root, Node *minNode, Node *maxNode)
{
    if (!root)
        return true;

    // If node value violates the min/max constraint
    if ((minNode && root->data <= minNode->data) ||
        (maxNode && root->data >= maxNode->data))
        return false;

    // Recur for left and right subtrees
    return isBSTUtil(root->left, minNode, root) &&
           isBSTUtil(root->right, root, maxNode);
}

bool isBST(Node *root)
{
    return isBSTUtil(root, nullptr, nullptr);
}

// ---------------------------------------------------
// Main Function
// ---------------------------------------------------
int main()
{
    Node *root = nullptr;

    // Constructing a valid BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // Check if it’s a BST
    if (isBST(root))
        cout << " The tree is a BST." << endl;
    else
        cout << " The tree is NOT a BST." << endl;

    // Make it invalid manually for test
    root->right->left->left = new Node(10);

    cout << "\nAfter modification (invalid case): ";
    cout << (isBST(root) ? " BST" : " Not BST") << endl;

    return 0;
}
