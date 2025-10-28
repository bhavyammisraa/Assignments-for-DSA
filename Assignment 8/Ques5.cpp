#include <iostream>
#include <stack>
using namespace std;

// Structure for a BST node
struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// Function to insert a node in BST (iterative)
Node *insert(Node *root, int val)
{
    Node *newNode = new Node(val);
    if (!root)
        return newNode;

    Node *curr = root;
    Node *parent = nullptr;

    while (curr != nullptr)
    {
        parent = curr;
        if (val < curr->data)
            curr = curr->left;
        else if (val > curr->data)
            curr = curr->right;
        else
            return root; // duplicate not inserted
    }

    if (val < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

// -----------------------------------------------------------
// ✅ Iterative Inorder Traversal (using Stack)
// -----------------------------------------------------------
void inorderIterative(Node *root)
{
    stack<Node *> st;
    Node *curr = root;

    while (curr || !st.empty())
    {
        while (curr)
        {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        cout << curr->data << " ";

        curr = curr->right;
    }
}

// -----------------------------------------------------------
// Optional: Iterative Preorder and Postorder (for reference)
// -----------------------------------------------------------
void preorderIterative(Node *root)
{
    if (!root)
        return;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *curr = st.top();
        st.pop();
        cout << curr->data << " ";
        if (curr->right)
            st.push(curr->right);
        if (curr->left)
            st.push(curr->left);
    }
}

void postorderIterative(Node *root)
{
    if (!root)
        return;
    stack<Node *> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        Node *curr = st1.top();
        st1.pop();
        st2.push(curr);
        if (curr->left)
            st1.push(curr->left);
        if (curr->right)
            st1.push(curr->right);
    }
    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

// -----------------------------------------------------------
// Main Function
// -----------------------------------------------------------
int main()
{
    Node *root = nullptr;

    // Build a sample BST
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : arr)
        root = insert(root, x);

    cout << "Iterative Inorder Traversal: ";
    inorderIterative(root);
    cout << endl;

    cout << "Iterative Preorder Traversal: ";
    preorderIterative(root);
    cout << endl;

    cout << "Iterative Postorder Traversal: ";
    postorderIterative(root);
    cout << endl;

    return 0;
}
