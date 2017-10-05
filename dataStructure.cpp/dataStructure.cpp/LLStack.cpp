#pragma once
#include "Header.h"

class LLNode {
public:
	int data;
	LLNode * next;
	LLNode(int d) {
		data = d;
		next = 0;
	}
	LLNode() {
		data = -1;
		next = 0;
	}
};


class LLStack {
private:
	LLNode **head;

public: 
	LLStack()
	{
		head = NULL;
	}
	int top() {
		if (isEmpty())
			return -1;
		return (*head)->data;
	}
	void push(int newItem) {
		LLNode p = LLNode(newItem);
		LLNode *pptr = &p ;
		pptr->data = newItem;
		if (isEmpty())
			pptr->next = 0;
		else
			pptr->next = *head;
		head = &pptr;
	}
	int pop() {
		LLNode * prevTop;
		int val;
		if (isEmpty())		//will possibly need to be changed
			return -1;
		val = (*head)->data;
		prevTop = *head;
		head = &((*head)->next);
		delete(prevTop);
		return val;
	}
	bool isEmpty() {
		return head == NULL;
	}
};


void testLLStack()
{
	cout << "LLStack test" << endl;
	/*LLStack lls;
	lls.push(3);
	lls.push(4);
	lls.push(5);
	lls.top() != 5 ? cout << "Error with top()" << endl : cout << "top() works" << endl;
	lls.pop() != 5 ? cout << "Error with pop()" << endl : cout << "pop() works" << endl;
	lls.isEmpty() ? cout << "Error with empty()" << endl : cout << "empty() works" << endl;*/
}