#include "Header.h"


class ArrayQueue {
private:
	int queue[10];
	int capacity = 10;
	int head = 0;		//will be the index of the value to be dequeued
	int tail = 0;		//will be ONE PAST the last entry

	//will not have a resize method, will just wrap around
public:
	ArrayQueue()
	{
		for (int i = 0; i < capacity; i++)
			queue[i] = -1;
	}
	int front()
	{
		return queue[head];
	}
	int back()
	{
		if (tail == 0)
		{
			return queue[capacity - 1];
		}
		return queue[tail-1];
	}
	void enqueue(int val)
	{
		queue[tail++] = val;
		if (tail == capacity)	//need to wrap around
			tail = 0;
	}
	void dequeue()
	{
		//shouldn't need to remove the data, just move the head forward
		head++;
		if (head == capacity) //wrap around
		{
			head = 0;
		}
	}
	bool empty()
	{
		bool full = (head == tail);
		return full;
	}
	int size()
	{
		//need to see if thise is the capacity or the number of elements
		return capacity;
	}
	bool full()
	{
		if (head == 0) {
			//nothing has been dequeued
		}
		return (tail + 1) == head;
	}
	void printInfo()
	{
		cout << "Head " << head << endl;
		cout << "Tail " << tail << endl;
		for (int i = 0; i < capacity; i++)
			cout << queue[i] << "|";
		cout << endl;
	}

};


void testArrayQueue()
{
	cout << "Test Array Queue" << endl;
	ArrayQueue aq;
	assert(aq.empty(), true);
	aq.enqueue(5);
	aq.enqueue(6);
	aq.enqueue(15);
	int val = aq.front();
	assert(5, val);
	aq.dequeue();
	aq.printInfo();
	aq.enqueue(10);
	aq.enqueue(8);
	aq.printInfo();
}