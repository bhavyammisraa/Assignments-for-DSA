#include <iostream>
using namespace std;


class DoublyNode {
public:
    int data;
    DoublyNode* prev;
    DoublyNode* next;

    DoublyNode(int val) {
        data = val;
        prev = next = nullptr;
    }
};

class DoublyLinkedList {
private:
    DoublyNode* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int val) {
        DoublyNode* newNode = new DoublyNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int val) {
        DoublyNode* newNode = new DoublyNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        DoublyNode* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int key, int val) {
        DoublyNode* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found.\n";
            return;
        }
        DoublyNode* newNode = new DoublyNode(val);
        newNode->next = temp->next;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
        DoublyNode* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found.\n";
            return;
        }
        DoublyNode* newNode = new DoublyNode(val);
        newNode->prev = temp->prev;
        newNode->next = temp;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(int key) {
        if (!head) return;
        DoublyNode* temp = head;

        // If head node itself holds the key
        if (temp->data == key) {
            head = temp->next;
            if (head)
                head->prev = nullptr;
            delete temp;
            return;
        }

        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found.\n";
            return;
        }

        if (temp->next)
            temp->next->prev = temp->prev;
        if (temp->prev)
            temp->prev->next = temp->next;
        delete temp;
    }

    void searchNode(int key) {
        DoublyNode* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << key << " not found.\n";
    }

    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        DoublyNode* temp = head;
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

// ===============================
// CIRCULAR LINKED LIST IMPLEMENTATION
// ===============================
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
private:
    CNode* last;
public:
    CircularLinkedList() {
        last = nullptr;
    }

    void insertAtBeginning(int val) {
        CNode* newNode = new CNode(val);
        if (!last) {
            last = newNode;
            last->next = last;
            return;
        }
        newNode->next = last->next;
        last->next = newNode;
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

    void insertAfter(int key, int val) {
        if (!last) return;
        CNode* temp = last->next;
        do {
            if (temp->data == key) {
                CNode* newNode = new CNode(val);
                newNode->next = temp->next;
                temp->next = newNode;
                if (temp == last)
                    last = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != last->next);
        cout << "Node " << key << " not found.\n";
    }

    void deleteNode(int key) {
        if (!last) return;
        CNode* curr = last->next;
        CNode* prev = last;

        do {
            if (curr->data == key) {
                if (curr == last && curr == last->next) {
                    delete curr;
                    last = nullptr;
                    return;
                }
                prev->next = curr->next;
                if (curr == last)
                    last = prev;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != last->next);

        cout << "Node " << key << " not found.\n";
    }

    void searchNode(int key) {
        if (!last) return;
        CNode* temp = last->next;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != last->next);
        cout << "Node " << key << " not found.\n";
    }

    void display() {
        if (!last) {
            cout << "List is empty.\n";
            return;
        }
        CNode* temp = last->next;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << "\n";
    }
};

// ===============================
// MAIN MENU
// ===============================
int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, val, key;
    int listType;

    cout << "Choose Linked List Type:\n1. Doubly Linked List\n2. Circular Linked List\nEnter choice: ";
    cin >> listType;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Insert Before a Node (Only for DLL)\n";
        cout << "5. Delete a Node\n";
        cout << "6. Search a Node\n";
        cout << "7. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                (listType == 1) ? dll.insertAtBeginning(val) : cll.insertAtBeginning(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                (listType == 1) ? dll.insertAtEnd(val) : cll.insertAtEnd(val);
                break;

            case 3:
                cout << "Enter key (after which to insert): ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                (listType == 1) ? dll.insertAfter(key, val) : cll.insertAfter(key, val);
                break;

            case 4:
                if (listType == 2) {
                    cout << "This operation is not supported for Circular Linked List.\n";
                    break;
                }
                cout << "Enter key (before which to insert): ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                dll.insertBefore(key, val);
                break;

            case 5:
                cout << "Enter node value to delete: ";
                cin >> key;
                (listType == 1) ? dll.deleteNode(key) : cll.deleteNode(key);
                break;

            case 6:
                cout << "Enter node value to search: ";
                cin >> key;
                (listType == 1) ? dll.searchNode(key) : cll.searchNode(key);
                break;

            case 7:
                (listType == 1) ? dll.display() : cll.display();
                break;

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
