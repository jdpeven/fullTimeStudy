#include "Header.h"
#include <vector>

vector<int> quicksort(vector<int> input)
{
	vector<int> quick;
	return quick;
}

vector<int> mergesort(vector<int> input)
{
	vector<int> merged;
	return merged;
}

bool isSorted(vector<int> v)
{
	if (v.empty() || v.size() == 1)
	{
		return true;
	}
	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i] > v[i + 1])
			return false;
	}
	return true;
}

vector<int> merge2sorted(vector<int> a, vector<int> b)
{
	int i;
	int j;
	vector<int> c;
	for (i = 0, j = 0; i < a.size() && j < b.size();)
	{
		if (a[i] <= b[j]) //need to append a[i]
		{
			c.push_back(a[i]);
			i++;
		}
		else if (b[j] < a[i])
		{
			c.push_back(b[j]);
			j++;
		}
	}
	if (i < a.size())	//a is longer than b
	{
		for (int k = i-1; k < a.size(); k++)
			c.push_back(a[k]);
	}
	if (j < b.size())
	{
		for (int l = i-1; l < b.size(); l++)
		{
			c.push_back(b[l]);
		}
	}
	return c;
}

void printVector(vector<int> a)
{
	cout << '{';
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << ',';
	}
	cout << '}';
}

void testSort()
{
	vector<int> a{ 8,2,3,5,2,3,6,8 };
	vector<int> b{ 8,3,5,4,2,1,4,7,8,9,6,3 };
	vector<int> sortedA{ 1,3,5,7,8,9,12 };
	vector<int> sortedB{ 1,5,7,8,9,10,23,24 };
	//a = quicksort(a);
	//b = mergesort(b);
	assert(false == isSorted(a));
	assert(false == isSorted(b));
	assert(true == isSorted(sortedA));
	assert(true == isSorted(sortedB));
	vector<int> sortedC = merge2sorted(sortedA, sortedB);
	assert(true == isSorted(sortedC));
	printVector(sortedC);

}