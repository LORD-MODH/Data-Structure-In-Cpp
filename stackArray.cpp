#include<iostream>
using namespace std;

class stack {
private:
	int top, * arr, cap;
public:
	stack(int n) {
		top = -1;
		cap = n;
		arr = new int[cap];
		for (int i = 0; i < cap; i++) {
			arr[i] = 0;
		}
	}
	
	~stack() {
		delete[] arr;
	}
	
	bool isfull() {
		if (top == cap - 1) return true; else return false;
	}
	
	void push(int v) {
		if (isfull()) {
			cout << "overflow"; return;
		}
		arr[++top] = v;
	}
	
	void pop() {
		if (top == -1) {
			cout << "underflow"; return;
		}
		top = top - 1;
	}
	
	void peek() {
		if (top == -1) {
			cout << "underflow"; return;
		}
		cout << arr[top];
	}
	
	void traverse() {
		if (top == -1) {
			cout << "underflow"; return;
		}
		for (int i = top; i >= 0; i--) {
			cout << arr[i];
		}
	}
	
	void resize(int ncap) {
		int* narr = new int[ncap];
		for (int i = 0; i < min(cap, ncap); i++) {
			narr[i] = arr[i];
		}
		for (int i = cap; i < ncap; i++) {
			narr[i] = 0;
		}
		delete[] arr;
		arr = narr;
		cap = ncap;
	}
};
int main() {
	stack s(5);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6); // this will cause an overflow, and print "overflow"

	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop(); // this will cause an underflow, and print "underflow"

	s.push(7);
	s.push(8);

	s.traverse(); // prints "84"

	s.peek(); // prints "8"

	return 0;
}
