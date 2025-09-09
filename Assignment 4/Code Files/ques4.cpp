//First non-repeating character in a string using Queue
#include <iostream>
using namespace std;

class Queue {
    char arr[100];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    void enqueue(char x) {
        arr[++rear] = x;
    }

    void dequeue() {
        if (!isEmpty()) front++;
    }

    char peek() {
        return isEmpty() ? '#' : arr[front];
    }
};

void firstNonRepeating(string s) {
    Queue q;
    int freq[256] = {0};  // frequency array

    for (char ch : s) {
        freq[(int)ch]++;
        q.enqueue(ch);

        while (!q.isEmpty() && freq[(int)q.peek()] > 1) {
            q.dequeue();
        }

        if (q.isEmpty())
            cout << -1 << " ";
        else
            cout << q.peek() << " ";
    }
    cout << "\n";
}

int main() {
    string s = "aabc";
    cout << "Input: " << s << "\nOutput: ";
    firstNonRepeating(s);
    return 0;
}
