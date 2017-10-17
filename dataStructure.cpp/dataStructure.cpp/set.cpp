#include "Header.h"
#include <set>
#include <vector>

set<int> setN(int k, set<int> s)
{
	set<int> ns;
	set<int>::iterator it;
	it = s.begin();
	it++;
	for (int i = 0; i < s.size(); i++)
	{
		if (k << i == 1)
		{
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
	for (int i = 0; i < s.size(); i++)
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
	set<int> myset = set<int>{ 1,3,4,5,6,7,8 };
	printSet(myset);
	vector<set<int>> ps = powerSet(myset);
	for (int i = 0; i < ps.size(); i++)
		printSet(ps[i]);
	cout << endl;

}