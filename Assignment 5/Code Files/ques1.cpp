#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeginning(int x) {
    Node* t = new Node;
    t->data = x;
    t->next = head;
    head = t;
}

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

void insertBefore(int val, int x) {
    if (!head) return;
    if (head->data == val) {
        insertBeginning(x);
        return;
    }
    Node* p = head;
    while (p->next && p->next->data != val) p = p->next;
    if (p->next) {
        Node* t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

void insertAfter(int val, int x) {
    Node* p = head;
    while (p && p->data != val) p = p->next;
    if (p) {
        Node* t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

void deleteBeginning() {
    if (!head) return;
    Node* t = head;
    head = head->next;
    delete t;
}

void deleteEnd() {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = NULL;
        return;
    }
    Node* p = head;
    while (p->next->next) p = p->next;
    delete p->next;
    p->next = NULL;
}

void deleteValue(int val) {
    if (!head) return;
    if (head->data == val) {
        Node* t = head;
        head = head->next;
        delete t;
        return;
    }
    Node* p = head;
    while (p->next && p->next->data != val) p = p->next;
    if (p->next) {
        Node* t = p->next;
        p->next = p->next->next;
        delete t;
    }
}

void search(int val) {
    Node* p = head;
    int pos = 1;
    while (p) {
        if (p->data == val) {
            cout << "Found at position " << pos << endl;
            return;
        }
        p = p->next;
        pos++;
    }
    cout << "Not found" << endl;
}

void display() {
    Node* p = head;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int ch, x, val;
    while (true) {
        cout << "1.Insert Beginning\n2.Insert End\n3.Insert Before\n4.Insert After\n5.Delete Beginning\n6.Delete End\n7.Delete Value\n8.Search\n9.Display\n10.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cin >> x; insertBeginning(x); break;
            case 2: cin >> x; insertEnd(x); break;
            case 3: cin >> val >> x; insertBefore(val, x); break;
            case 4: cin >> val >> x; insertAfter(val, x); break;
            case 5: deleteBeginning(); break;
            case 6: deleteEnd(); break;
            case 7: cin >> val; deleteValue(val); break;
            case 8: cin >> val; search(val); break;
            case 9: display(); break;
            case 10: return 0;
        }
    }
}

