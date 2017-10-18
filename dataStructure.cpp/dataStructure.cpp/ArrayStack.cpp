#include "Header.h"

class ArrayStack {
private:
	int *stack;
	int capacity = 10;
	int size = 0;
	int topIndex = -1;

	void resize() {
		int newCapacity = 2 * capacity;
		int *newstack = (int*)malloc(newCapacity * sizeof(int));
		for (int i = 0; i < capacity; i++)
			newstack[i] = stack[i];
		for (int j = capacity; j < newCapacity; j++)
			newstack[j] = 0;
		stack = newstack;
		capacity = newCapacity;
	}
public:
	ArrayStack()
	{
		stack = (int*)malloc(capacity *sizeof(int));
		for (int i = 0; i < capacity; i++)
		{
			stack[i] = 0;
		}
	}
	int top() {
		return stack[topIndex];
	}
	void push(int newItem) {
		if (size == capacity)
			resize();
		topIndex++;
		stack[topIndex] = newItem;
		size++;
	}
	int pop() {
		if (isEmpty())		//will possibly need to be changed
			return -1;
		size--;
		return stack[topIndex--];
	}
	bool isEmpty() {
		return topIndex == -1;
	}
	void printStack()
	{
		cout << '[';
		for (int i = 0; i < capacity; i++)
			cout << stack[i] << ',';
		cout << ']' << endl;
	}
};


void testArrayStack() {
	cout << "Testing the ArrayStack" << endl;
	ArrayStack as;
	as.push(3);
	as.push(4);
	as.push(5);
	as.push(5);
	as.push(5);
	as.push(5);
	as.push(5);
	as.push(5);
	as.push(5);
	as.push(5);
	as.push(5);
	as.push(5);
	as.push(5);
	as.printStack();
	//should test push independantly
	assert(as.top() == 5 && "Error with top()");
	assert(as.pop() == 5 && "Error with pop()");
	assert(as.isEmpty() == false && "Error with empty()");
	//as.top() != 5 ? cout << "Error with top()" << endl : cout << "top() works" << endl;
	//as.pop() != 5 ? cout << "Error with pop()" << endl : cout << "pop() works" << endl;
	//as.isEmpty() ? cout << "Error with empty()" << endl : cout << "empty() works" << endl;
	cout << "Passed all asserts" << endl;

}