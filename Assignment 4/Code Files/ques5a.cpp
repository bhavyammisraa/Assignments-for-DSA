//Stack using Two Queues
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
    Queue q1, q2;

public:
    void push(int x) {
        q2.enqueue(x);
        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }
        // swap q1 and q2
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop() {
        if (q1.isEmpty()) {
            cout << "Stack is Empty!\n";
            return;
        }
        cout << q1.dequeue() << " popped\n";
    }

    void top() {
        if (q1.isEmpty()) {
            cout << "Stack is Empty!\n";
            return;
        }
        cout << "Top element: " << q1.peek() << "\n";
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
