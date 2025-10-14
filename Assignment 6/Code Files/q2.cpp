#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
    Node* last;
public:
    CircularLinkedList() {
        last = nullptr;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!last) {
            last = newNode;
            last->next = last;
            return;
        }
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    void displayWithRepeatHead() {
        if (!last) {
            cout << "List is empty\n";
            return;
        }
        Node* head = last->next;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << "\n";
    }
};

int main() {
    CircularLinkedList cll;
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        cll.insertAtEnd(val);
    }
    cll.displayWithRepeatHead();
    return 0;
}
