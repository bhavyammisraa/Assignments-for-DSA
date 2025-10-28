#include <iostream>
#include <list>
#include <vector>
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
// Store inorder traversal of BST in a list
// ---------------------------------------------------
void storeInorder(Node *root, list<int> &l)
{
    if (!root)
        return;
    storeInorder(root->left, l);
    l.push_back(root->data);
    storeInorder(root->right, l);
}

// ---------------------------------------------------
// Merge two sorted lists
// ---------------------------------------------------
list<int> mergeLists(list<int> &a, list<int> &b)
{
    list<int> result;
    auto i = a.begin(), j = b.begin();

    while (i != a.end() && j != b.end())
    {
        if (*i < *j)
            result.push_back(*i++);
        else
            result.push_back(*j++);
    }

    while (i != a.end())
        result.push_back(*i++);
    while (j != b.end())
        result.push_back(*j++);

    return result;
}

// ---------------------------------------------------
// Convert sorted list to a balanced BST
// ---------------------------------------------------
Node *sortedListToBST(list<int> &l, list<int>::iterator &it, int n)
{
    if (n <= 0)
        return nullptr;

    // Build left subtree
    Node *left = sortedListToBST(l, it, n / 2);

    // Root node
    Node *root = newNode(*it);
    ++it;

    // Build right subtree
    root->left = left;
    root->right = sortedListToBST(l, it, n - n / 2 - 1);

    return root;
}

// ---------------------------------------------------
// Merge two BSTs into a balanced BST
// ---------------------------------------------------
Node *mergeBSTs(Node *root1, Node *root2)
{
    // Step 1: Store inorder traversals
    list<int> list1, list2;
    storeInorder(root1, list1);
    storeInorder(root2, list2);

    // Step 2: Merge both sorted lists
    list<int> merged = mergeLists(list1, list2);

    // Step 3: Convert merged list to balanced BST
    auto it = merged.begin();
    return sortedListToBST(merged, it, merged.size());
}

// ---------------------------------------------------
// Print inorder traversal (to verify merged BST)
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
// Example usage
// ---------------------------------------------------
int main()
{
    /*
        BST 1:      3
                   / \
                  1   5

        BST 2:      4
                   / \
                  2   6
    */

    Node *root1 = newNode(3);
    root1->left = newNode(1);
    root1->right = newNode(5);

    Node *root2 = newNode(4);
    root2->left = newNode(2);
    root2->right = newNode(6);

    Node *mergedRoot = mergeBSTs(root1, root2);

    cout << "Inorder Traversal of Merged Balanced BST: ";
    printInorder(mergedRoot);
    cout << endl;

    return 0;
}