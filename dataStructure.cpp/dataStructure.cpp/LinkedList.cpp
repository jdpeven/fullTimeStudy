#include "Header.h"

class LLNode {
public:
	int data;
	LLNode * next;
	LLNode(int d) {
		data = d;
		next = nullptr;
	}
	LLNode() {
		data = -1;
		next = nullptr;
	}
};


class LinkedList {
private:
	LLNode *head;
public:
	LinkedList()
	{
		head = nullptr;
		//*head = nullptr;
	}

	LinkedList(int val)
	{
		LLNode* h = new LLNode();
		h->data = val;
		h->next = nullptr;
		head = h;
	}

	int size()
	{
		int s = 0;
		if (isEmpty())
		{
			return 0;
		}
		LLNode * temp = head;
		while (temp != nullptr)
		{
			s++;
			temp = temp->next;
		}
		return s;
	}

	bool isEmpty()
	{
		return head == nullptr;
	}

	int valueAt(int index)
	{
		LLNode *temp = head;
		int v = 0;
		for (int i = 0; i < index && temp != nullptr; i++)
		{
			temp = temp->next;
		}
		if (temp != nullptr)
			v = temp->data;
		else
			v = -1;
		return v;
	}

	void insertAtFront(int val)
	{
		LLNode * newNode = new LLNode();
		newNode->data = val;
		newNode->next = head;

		head = newNode;
	}

	int removeFromFront()
	{
		int v = head->data;
		head = head->next;
		return v;
	}

	void insertAtBack(int val)
	{
		LLNode * newNode = new LLNode();
		newNode->data = val;
		newNode->next = nullptr;

		LLNode *temp;
		if (head == nullptr)
		{
			head = newNode;
			return;
		}
		temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}

	int removeFromBack()
	{
		LLNode *temp;
		temp = head;
		int v = -1;
		while (temp->next->next != nullptr)
		{
			temp = temp->next;
		}
		//we're not at the second to last element
		v = temp->next->data;
		delete temp->next;
		temp->next = nullptr;
		return v;
	}
	int front()
	{
		int v = -1;
		if (head != nullptr)
			v = head->data;
		return v;
	}

	int back()
	{
		int v = -1;
		LLNode *temp = head;
		if (temp == nullptr)
			return v;
		while (temp->next != nullptr)
			temp = temp->next;
		v = temp->data;
		return v;
	}

	void insert(int index, int value)
	{
		LLNode * temp = head;
		LLNode * newNode = new LLNode();
		newNode->data = value;

		if (index == 0)
		{
			insertAtFront(value);
			return;
		}

		for (int i = 1; i < index && temp != nullptr; i++)
		{
			temp = temp->next;
		}
		
		if (temp == nullptr)	//index was greater than size
		{
			return;
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}

	void erase(int index)
	{
		LLNode * temp = head;
		if (index == 0)
		{
			removeFromFront();
			return;
		}
		for (int i = 1; i < index && temp!=nullptr; i++)
		{
			temp = temp->next;
		}
		temp->next = temp->next->next;
	}
	
	void printList()
	{
		LLNode * temp = head;
		//temp = head;
		if (head == nullptr) 
		{
			cout << "NULL" << endl;
			return;
		}
		while (temp != nullptr)
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}

};

void testLL()
{
	cout << "Testing LL" << endl;
	LinkedList ll = LinkedList();
	ll.printList();
	assert(ll.isEmpty(), true);
	assert(ll.size() == 0);
	assert(ll.front() == -1);
	assert(ll.back() == -1);
	ll.insertAtFront(20);
	ll.insertAtBack(5);
	ll.insertAtBack(6);
	ll.insertAtBack(7);
	ll.insertAtBack(10);
	ll.insertAtFront(2);
	assert(ll.size() == 6);
	assert(ll.valueAt(0) == 2);
	assert(ll.valueAt(1) == 20);
	assert(ll.valueAt(15) == -1);
	ll.printList();
	assert(ll.removeFromFront(), 2);
	assert(ll.removeFromBack(), 10);
	ll.printList();
	assert(ll.front(), 20);
	assert(ll.back(), 7);
	ll.insert(2, 44);
	ll.insert(0, 14);
	ll.insert(200, 10);
	ll.printList();
	ll.erase(0);
	ll.printList();
	
}
