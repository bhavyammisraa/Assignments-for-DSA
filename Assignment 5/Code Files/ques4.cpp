#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertEnd(int x) {
    Node* t = new Node;
    t->data = x;
    t->next = NULL;
    if (!head) head = t;
    else {
        Node* p = head;
        while (p->next) p = p->next;
        p->next = t;
    }
}

void reverseList() {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void display() {
    Node* p = head;
    while (p) {
        cout << p->data << "->";
        p = p->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertEnd(x);
    }
    reverseList();
    display();
    return 0;
}

