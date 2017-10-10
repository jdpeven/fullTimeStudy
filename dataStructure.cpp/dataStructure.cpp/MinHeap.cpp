#include "Header.h"

class MinHeap {
private:
	int* heap;
	int tail = 1;
	int size = 20;
public:
	MinHeap()
	{
		//default to twenty
		heap = (int*)malloc((size + 1) * sizeof(int));
		for (int i = 1; i < 20; i++)
		{
			heap[i] = -1;
		}
	}
	MinHeap(int s)
	{
		size = s;
		heap = (int*)malloc((size + 1) * sizeof(int));
	}
	MinHeap(int * arr, int s)
	{
		heapify(arr, s);
	}
	bool isEmpty()
	{
		return tail == 1;
	}
	void insert(int val)
	{
		heap[tail++] = val;
		siftUp();
	}
	void siftUp()
	{
		int currentIndex = tail;
		int nextIndex = tail / 2;
		int temp;
		while (heap[currentIndex] < heap[nextIndex] && currentIndex != 1)
		{
			temp = heap[currentIndex];
			heap[currentIndex] = heap[nextIndex];
			heap[nextIndex] = temp;
			currentIndex = nextIndex;
			nextIndex = currentIndex / 2;
		}
	}
	int getMin()
	{
		return heap[1];
	}
	int getSize()
	{
		return tail - 1;
	}
	int getCapacity()
	{
		return size;
	}
	int extractMax()
	{
		int returnVal = heap[1];
		heap[1] = heap[tail--];
		siftDown();
	}
	void siftDown()
	{

	}
	void printHeap()
	{
		for (int i = 1; i < size && heap[i] != -1; i++)
			cout << heap[i] << ",";
		cout << endl;
	}
	int *getHeap()
	{
		return heap;
	}
	int* MinHeap::heapify(int starter[], int s)
	{
		//will heapsort an array
		MinHeap mh;
		for (int i = 0; i < s; i++)
			mh.insert(starter[i]);
	}
};



void testMinHeap()
{
	
}