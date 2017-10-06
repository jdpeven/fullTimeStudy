#include "Header.h"

class ArrayStack {
private:
	int stack[10];
	int capacity = 10;
	int size = 0;
	int topIndex = 0;

	void resize() {
		//will be called when capacity == size
	}
public:
	int top() {
		return stack[topIndex];
	}
	void push(int newItem) {
		if (size == capacity)
			resize();
		topIndex++;
		stack[topIndex] = newItem;
	}
	int pop() {
		if (isEmpty())		//will possibly need to be changed
			return -1;
		return stack[topIndex--];
	}
	bool isEmpty() {
		return topIndex == -1;
	}
};


void testArrayStack() {
	cout << "Testing the ArrayStack" << endl;
	ArrayStack as;
	as.push(3);
	as.push(4);
	as.push(5);
	//should test push independantly
	assert(as.top() == 5 && "Error with top()");
	assert(as.pop() == 5 && "Error with pop()");
	assert(as.isEmpty() == false && "Error with empty()");
	//as.top() != 5 ? cout << "Error with top()" << endl : cout << "top() works" << endl;
	//as.pop() != 5 ? cout << "Error with pop()" << endl : cout << "pop() works" << endl;
	//as.isEmpty() ? cout << "Error with empty()" << endl : cout << "empty() works" << endl;
	cout << "Passed all asserts" << endl;

}