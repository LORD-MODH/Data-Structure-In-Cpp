#include<iostream>
using namespace std;

class stack {
	private:
		int top, cap, * arr;
	public :
		stack(int s) {
			top = -1;
			cap = s;
			arr = new int[s];
			for (int i = 0; i < cap; i++) {
				arr[i] = 0;
			}
		}
		
		~stack() {
			delete[] arr;
		}
		
		bool isfull() {
			if (top == cap - 1) return 1;
			else return 0;
		}
		
		bool isempty() {
			if (top ==-1) return 1;
			else return 0;
		}
		
		void push(int value) {
			if (isfull()) cout << "overflow";
			else {
				arr[++top] = value;
			}
		}
		
		void pop() {
			if (isempty()) cout << "underflow";
			else top--;
		}
		
		void peek() {
			if (isempty()) cout << "underflow";
			else cout << arr[top];
		}
		
		void disp() {
			if (isempty()) cout << "underflow";
			else {
				for (int i = top; i >=0; i--) {
					cout << arr[i];
				}
			}
		}
		
		void resize(){
      intnewCapacity = 2 * capacity;
      int* newArr = new int[newCapacity];
      for(int i = 0; i < capacity; i++) {
          newArr[i] = arr[i];
      }
      for(int i = capacity; i < newCapacity; i++) {
          newArr[i] = 0;
      }
      delete[] arr;
      arr = newArr;
      capacity = newCapacity;
    }

		void count(){
			cout<<top+1; 
		}
};
int main() {
	stack a(10);
	a.push(0);
	a.push(1);
	a.pop();
	a.push(2);
	a.peek();
	a.disp();
}
