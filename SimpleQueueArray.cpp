#include<iostream>
using namespace std;

class queue {
	int cap, front, rear, * arr;
public:
	queue(int size) : cap(size), front(-1), rear(-1), arr(new int[cap]) {}
	~queue() { delete[] arr; }
	bool isempty() { return front == rear; }
	bool isfull() { return (rear - 1) % cap == front; }
	void enqueue(int value) {
		if (isfull()) {
			cout << "queue is full"; return;
		}
		if (isempty()) front = 0;
		rear = (rear + 1) % cap;
		arr[rear] = value;
	}
	void dequeue() {
		if (isempty()) {
			cout << "queue is empty"; return;
		}
		front = (front + 1) % cap;
	}
	int getf() {
		if (isempty()) {
			return -1;
		}
		return arr[front];
	}
	int getr() {
		if (isempty()) {
			return -1;
		}
		return arr[rear];
	}
};

int main() {
	// Create a queue with capacity 5
	queue q(5);

	// Enqueue some elements
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);

	// Dequeue an element
	q.dequeue();

	// Enqueue some more elements
	q.enqueue(4);
	q.enqueue(5);

	// Try to enqueue one more element (queue is full)
	q.enqueue(6);

	// Print the front and rear elements
	cout << "Front: " << q.getf() << endl;
	cout << "Rear: " << q.getr() << endl;

	// Dequeue all elements and print them
	while (!q.isempty()) {
		cout << q.getf() << " ";
		q.dequeue();
	}
	cout << endl;

	return 0;
}
