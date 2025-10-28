#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int val)
{
    Node *node = new Node{val, nullptr, nullptr};
    return node;
}

// Insert
Node *insert(Node *root, int val)
{
    if (!root)
        return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

// Recursive Search
Node *search(Node *root, int key)
{
    if (!root || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

// Non-Recursive Search
Node *searchNonRec(Node *root, int key)
{
    while (root && root->data != key)
        root = (key < root->data) ? root->left : root->right;
    return root;
}

Node *minValueNode(Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

Node *maxValueNode(Node *root)
{
    while (root && root->right)
        root = root->right;
    return root;
}

// Inorder Successor
Node *inorderSuccessor(Node *root, Node *node)
{
    if (node->right)
        return minValueNode(node->right);
    Node *succ = nullptr;
    while (root)
    {
        if (node->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (node->data > root->data)
            root = root->right;
        else
            break;
    }
    return succ;
}

// Inorder Predecessor
Node *inorderPredecessor(Node *root, Node *node)
{
    if (node->left)
        return maxValueNode(node->left);
    Node *pred = nullptr;
    while (root)
    {
        if (node->data > root->data)
        {
            pred = root;
            root = root->right;
        }
        else if (node->data < root->data)
            root = root->left;
        else
            break;
    }
    return pred;
}

int main()
{
    Node *root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    Node *key = search(root, 30);
    cout << "Search 30: " << (key ? "Found" : "Not Found") << endl;

    cout << "Minimum: " << minValueNode(root)->data << endl;
    cout << "Maximum: " << maxValueNode(root)->data << endl;
    cout << "Inorder Successor of 30: " << inorderSuccessor(root, key)->data << endl;
    cout << "Inorder Predecessor of 30: " << inorderPredecessor(root, key)->data << endl;
}
