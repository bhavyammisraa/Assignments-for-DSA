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

class LinkedList {
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void makeCircular() {
        if (!head) return;
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = head;
    }

    bool isCircular() {
        if (!head) return false;
        Node* temp = head->next;
        while (temp && temp != head)
            temp = temp->next;
        return (temp == head);
    }
};

int main() {
    LinkedList list;
    int n, val, choice;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertAtEnd(val);
    }
    cout << "Make the list circular? (1-Yes, 0-No): ";
    cin >> choice;
    if (choice == 1)
        list.makeCircular();
    if (list.isCircular())
        cout << "The linked list is circular.\n";
    else
        cout << "The linked list is not circular.\n";
    return 0;
}
