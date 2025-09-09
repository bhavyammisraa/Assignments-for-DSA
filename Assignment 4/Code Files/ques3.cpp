//Interleave first half of queue with second half
#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front, rear, size;

public:
    Queue(int n = 100) {
        front = 0;
        rear = -1;
        size = n;
    }

    bool isEmpty() {
        return front > rear;
    }

    void enqueue(int x) {
        if (rear == size - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        return arr[front++];
    }

    int peek() {
        return isEmpty() ? -1 : arr[front];
    }

    int getSize() {
        return (rear - front + 1);
    }

    void display() {
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << "\n";
    }
};

void interleaveQueue(Queue &q) {
    int n = q.getSize();
    if (n % 2 != 0) {
        cout << "Queue size should be even!\n";
        return;
    }

    int half = n / 2;
    Queue firstHalf(100);

    for (int i = 0; i < half; i++) {
        firstHalf.enqueue(q.dequeue());
    }

    // Now interleave
    while (!firstHalf.isEmpty()) {
        q.enqueue(firstHalf.dequeue());
        q.enqueue(q.dequeue());
    }
}

int main() {
    Queue q(100);
    int arr[] = {4, 7, 11, 20, 5, 9};
    for (int x : arr) q.enqueue(x);

    cout << "Original Queue: ";
    q.display();

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    q.display();
    return 0;
}
