#include "Header.h"
#include <queue>

class BSTNode {
private:
	int data;
	BSTNode * left = 0;
	BSTNode * right = 0;
public:
	BSTNode(int val)
	{
		data = val;
		left = 0;
		right = 0;
	}
	void add(int val)
	{
		//do duplicates
		if (val < data) {
			if (left) {
				left->add(val);
			}
			else
			{
				BSTNode * newNode;
				newNode = (BSTNode*)malloc(sizeof(BSTNode));
				newNode->data = val;
				newNode->left = 0;
				newNode->right = 0;
				left = newNode;
			}
		}
		else if (val > data) {
			if (right) {
				right->add(val);
			}
			else {
				BSTNode * newNode;
				newNode = (BSTNode*)malloc(sizeof(BSTNode));
				newNode->data = val;
				newNode->left = 0;
				newNode->right = 0;
				right = newNode;
			}
		}
	}
	void remove()
	{

	}
	bool find(int val)
	{
		if (val == data)
			return true;
		if (val < data && left) //it's less than us, and we have a left child
			return left->find(val);
		if (val > data && right)
			return right->find(val);
		return false;
	}
	void inOrderTraversal()
	{
		if (left != NULL)
			left->inOrderTraversal();
		cout << data << " ";
		if (right != NULL)
			right->inOrderTraversal();
	}
	void postOrderTraversal()
	{
		if (left != NULL)
			left->postOrderTraversal();
		if (right != NULL)
			right->postOrderTraversal();
		cout << data << " ";
	}
	void preOrderTraversal()
	{
		cout << data << " ";
		if (left != NULL)
			left->preOrderTraversal();
		if (right != NULL)
			right->preOrderTraversal();
	}
	void levelOrderTraversal()
	{
		queue<BSTNode *> myQ;
		BSTNode * temp;
		myQ.push(this);
		while (!myQ.empty()) {
			temp = myQ.front();
			cout << temp->data << " ";
			if (temp->left != NULL)
				myQ.push(temp->left);
			if (temp->right != NULL)
				myQ.push(temp->right);
			myQ.pop();
		}
	}
};

void testBST()
{
	cout << "Testing BST" << endl;
	BSTNode root(10);
	root.add(5);
	root.add(13);
	root.add(4);
	root.add(3);
	root.add(11);
	root.add(15);
	//root.find(5) == true ? cout << "Find works" << endl : cout << "Find doesn't work" << endl;
	//root.find(20) == false ? cout << "Find works" << endl : cout << "Find doesn't work" << endl;
	cout << "In Order Traversal: ";
	root.inOrderTraversal();
	cout << endl;
	cout << "Pre Order Traversal: ";
	root.preOrderTraversal();
	cout << endl;
	cout << "Post Order Traversal: ";
	root.postOrderTraversal();
	cout << endl;
	cout << "Level Order Traversal: ";
	root.levelOrderTraversal();
	cout << endl;
}