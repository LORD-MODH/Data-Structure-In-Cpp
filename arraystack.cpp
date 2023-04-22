#include <iostream>
using namespace std;

const int MAX = 10;
int stack[MAX], top = -1;

bool isempty() {
    return top == -1;
}

bool isfull() {
    return top == MAX - 1;
}

void push(int value) {
    if (isfull()) {
        cout << "Stack overflow" << endl;
    }
    else {
        stack[++top] = value;
    }
}

void pop() {
    if (isempty()) {
        cout << "Stack underflow" << endl;
    }
    else {
        top--;
    }
}

void peek() {
    if (isempty()) {
        cout << "Stack is empty" << endl;
    }
    else {
        cout << stack[top] << endl;
    }
}

void print() {
    if (isempty()) {
        cout << "Stack is empty" << endl;
    }
    else {
        for (auto i = 0; i <= top; i++) {
            cout << stack[i] << endl;
        }
    }
}

int main() {
    push(0); push(1); push(2);
    pop();
    push(3);
    print();
    return 0;
}
