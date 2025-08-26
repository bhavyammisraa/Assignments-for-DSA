//Write a program for the evaluation of a Postfix expression.
#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(int x) {
        if (!isFull()) arr[++top] = x;
    }

    int pop() {
        if (!isEmpty()) return arr[top--];
        return -1;
    }
};

int evaluatePostfix(string postfix) {
    Stack s;

    for (char c : postfix) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            int val2 = s.pop();
            int val1 = s.pop();

            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.pop();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    cout << "Evaluated result: " << evaluatePostfix(postfix) << endl;
    return 0;
}
