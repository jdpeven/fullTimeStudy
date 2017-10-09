#include "Header.h"
#include <vector>

class Graph {
private:

	vector<GraphNode *> nodes;
public:
	bool dfs(int a_ID, int b_ID)
	{
		return true;
	}
	bool bfs(int a_ID, int b_ID)
	{

	}
	int **createMatrix()
	{
		int size = nodes.size();
		//initialize the array
		int ** arr = NULL;
		arr = new int *[size + 1];
		for (int i = 0; i < size + 1; i++)
		{
			arr[i] = new int[size + 1];
		}
		//populate the array
		for (int j = 1; j < size + 1; j++)
		{
			arr[0][j] = nodes[j]->getID();
		}
		for (int k = 1; k < size + 1; k++)
		{
			arr[k][0] = nodes[k]->getID();
		}
	}
	void addNode(int val)
	{
		GraphNode * n;
		n = new GraphNode(val, nodes.size());
		nodes.push_back(n);
	}
	void insertUniDirectional(int a_ID, int b_ID)
	{

	}
	void insertBiDirectional(int a_ID, int b_ID)
	{

	}
};

class GraphNode {
private:
	int data;
	vector<GraphNode *> neighbors;
	int id;
public:
	GraphNode(int val, int ident)
	{
		data = val;
		id = ident;
	}
	int getID()
	{
		return id;
	}
	
};

void testGraph()
{
	
}