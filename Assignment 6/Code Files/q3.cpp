#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) {
        data = val;
        prev = next = nullptr;
    }
};

class DoublyLinkedList {
    DNode* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    int getSize() {
        int count = 0;
        DNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

class CNode {
public:
    int data;
    CNode* next;
    CNode(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
    CNode* last;
public:
    CircularLinkedList() {
        last = nullptr;
    }

    void insertAtEnd(int val) {
        CNode* newNode = new CNode(val);
        if (!last) {
            last = newNode;
            last->next = last;
            return;
        }
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    int getSize() {
        if (!last) return 0;
        int count = 0;
        CNode* temp = last->next;
        do {
            count++;
            temp = temp->next;
        } while (temp != last->next);
        return count;
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int n, val;

    cout << "Enter number of nodes for Doubly Linked List: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        dll.insertAtEnd(val);
    }
    cout << "Size of Doubly Linked List: " << dll.getSize() << "\n";

    cout << "Enter number of nodes for Circular Linked List: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        cll.insertAtEnd(val);
    }
    cout << "Size of Circular Linked List: " << cll.getSize() << "\n";

    return 0;
}
