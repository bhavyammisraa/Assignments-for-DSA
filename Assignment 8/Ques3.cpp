#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int val)
{
    return new Node{val, nullptr, nullptr};
}

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

Node *minValueNode(Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

Node *deleteNode(Node *root, int key)
{
    if (!root)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;
        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int maxDepth(Node *root)
{
    if (!root)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node *root)
{
    if (!root)
        return 0;
    return 1 + min(minDepth(root->left), minDepth(root->right));
}
int main()
{
    Node *root = nullptr;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);

    cout << "Max Depth: " << maxDepth(root) << endl;
    cout << "Min Depth: " << minDepth(root) << endl;

    root = deleteNode(root, 5);
    cout << "After deleting 5, Max Depth: " << maxDepth(root) << endl;
    cout << "After deleting 5, Min Depth: " << minDepth(root) << endl;

    return 0;
}