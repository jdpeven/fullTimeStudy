#include "Header.h"
#include <set>
#include <vector>

set<int> setN(int k, set<int> s)
{
	set<int> ns;
	set<int>::iterator it;
	it = s.begin();
	it++;
	for (int i = 0; i < log2(k) + 1; i++)
	{
		if ((k >> i) & 1 != 0)
		{
			if(it != s.end())
				ns.insert((*it));
		}
		if(it != s.end())
			it++;
	}
	return ns;
}


vector<set<int>> powerSet(set<int> s)
{
	vector<set<int>> ps;
	for (int i = 0; i < pow(2, s.size()); i++)
		ps.push_back(setN(i, s));
	return ps;
}

void printSet(set<int> s)
{
	set<int>::iterator it;
	cout << '{';
	for (it = s.begin(); it != s.end(); ++it)
	{
		cout << (*it) << ",";
	}
	cout << "}" << endl;
}


void testSet()
{
	//cout << (2 & (1 << 1)) << endl;
	set<int> myset = set<int>{ 1,3,4,5,6,7,8 };
	printSet(myset);
	vector<set<int>> ps = powerSet(myset);
	cout << "size should be " << pow(2, myset.size()) << ". Actually is: " << ps.size() << endl;
	/*for (int i = 0; i < ps.size(); i++)
		printSet(ps[i]);*/
	cout << endl;
}