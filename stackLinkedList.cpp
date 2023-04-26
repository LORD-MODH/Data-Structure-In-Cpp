#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

node* top = nullptr;

bool isempty(){
	if (top == nullptr) return 1; else return 0;
}

void push(int data) {
	node* newnode = new node;
	newnode->data = data;
	newnode->next = top;
	top = newnode;
}

void pop() {
	if (isempty()) { cout << "underflow"; return;}
	else {
		node* temp = top;
		top = top->next;
		delete temp;
	}
}

void peek() {
	if (isempty()) { cout << "underflow"; return; }
	else {
		cout << top->data;
	}
}

void traverse() {
	if (isempty()) { cout << "underflow"; return; }
	else {
		node* current = top;
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
	}
}

int main() {
	push(0);
  push(1); 
  push(2); 
  push(3);
	pop();
	traverse();
	peek();
}
