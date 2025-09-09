//Stack using One Queue
#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    void enqueue(int x) {
        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        return arr[front++];
    }

    int size() {
        return rear - front + 1;
    }

    int peek() {
        return isEmpty() ? -1 : arr[front];
    }
};

class Stack {
    Queue q;

public:
    void push(int x) {
        int n = q.size();
        q.enqueue(x);
        for (int i = 0; i < n; i++) {
            q.enqueue(q.dequeue());
        }
    }

    void pop() {
        if (q.isEmpty()) {
            cout << "Stack is Empty!\n";
            return;
        }
        cout << q.dequeue() << " popped\n";
    }

    void top() {
        if (q.isEmpty()) {
            cout << "Stack is Empty!\n";
            return;
        }
        cout << "Top element: " << q.peek() << "\n";
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.top();
    s.pop();
    s.top();
    return 0;
}
