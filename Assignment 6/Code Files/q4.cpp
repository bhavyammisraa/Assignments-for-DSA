#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;
    Node(char val) {
        data = val;
        prev = next = nullptr;
    }
};

class DoublyLinkedList {
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() {
        head = tail = nullptr;
    }

    void insertAtEnd(char val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    bool isPalindrome() {
        if (!head) return true;
        Node* left = head;
        Node* right = tail;
        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main() {
    DoublyLinkedList dll;
    int n;
    char ch;
    cout << "Enter number of characters: ";
    cin >> n;
    cout << "Enter characters: ";
    for (int i = 0; i < n; i++) {
        cin >> ch;
        dll.insertAtEnd(ch);
    }
    if (dll.isPalindrome())
        cout << "The doubly linked list is a palindrome.\n";
    else
        cout << "The doubly linked list is not a palindrome.\n";
    return 0;
}
