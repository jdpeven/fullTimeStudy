#include "Header.h"
#include <queue>

class BSTNode {
private:
	int data;
	BSTNode * left = nullptr;
	BSTNode * right = nullptr;
public:
	BSTNode(int val)
	{
		data = val;
		left = nullptr;
		right = nullptr;
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
	bool remove(int val)
	{
		//will find the node's parent, and replace it with the child nodes left nodes largest child
		//if it has not left node, it will replace with it's right nodes smallest child
		//if it has neither a left nor right node. it will be deleted
		BSTNode * parentNode = nullptr;
		parentNode = findParent(val);
		if (parentNode = nullptr) {
			cout << val << " not found in tree, returning false" << endl;
			return false;
		}
		//important to remember that we can't affect the parent's link to this node
		//so a deletion will be finding a node to replace, replacing nodeToRemoves values with that,
		//and free the other node.
	}
	BSTNode * findParent(int val)
	{
		//used in the remove function
		if(val < data)
			if (left != nullptr) {
				if (left->data == val)
					return this;
				else
					return left->findParent(val);
			}
			//the value SHOULD be in the left subtree, but it has no left child
			else 
				return nullptr;
		else if (val > data)
		{
			if (right != nullptr) {
				if (right->data == val)
					return this;
				else
					return right->findParent(val);
			}
			else
				return nullptr;
		}
	}
	BSTNode * find(int val)
	{
		if (val == data)
			return this;
		if (val < data && left) //it's less than us, and we have a left child
			return left->find(val);
		if (val > data && right)
			return right->find(val);
		return nullptr;
	}
	BSTNode * getLargestChild()
	{
		//will be called in the remove function.
		BSTNode * largestChild = this->right;
		if (largestChild == nullptr)	//no right children
			return this;				//this node is it's "largest child"
		while (largestChild->right != nullptr)
			largestChild = largestChild->right;
		return largestChild;
	}
	void inOrderTraversal()
	{
		if (left != nullptr)
			left->inOrderTraversal();
		cout << data << " ";
		if (right != nullptr)
			right->inOrderTraversal();
	}
	void postOrderTraversal()
	{
		if (left != nullptr)
			left->postOrderTraversal();
		if (right != nullptr)
			right->postOrderTraversal();
		cout << data << " ";
	}
	void preOrderTraversal()
	{
		cout << data << " ";
		if (left != nullptr)
			left->preOrderTraversal();
		if (right != nullptr)
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
			if (temp->left != nullptr)
				myQ.push(temp->left);
			if (temp->right != nullptr)
				myQ.push(temp->right);
			myQ.pop();
		}
	}
	void bfs()
	{
		queue<BSTNode *> myQ;
		myQ.push(this);
		while (!myQ.empty())
		{
			cout << myQ.front()->data << ",";
			if (myQ.front()->left != nullptr)
				myQ.push(myQ.front()->left);
			if (myQ.front()->right != nullptr)
				myQ.push(myQ.front()->right);
			myQ.pop();
		}
		cout << endl;
	}
	void dfs()
	{
		cout << this->data << ",";
		if (this->left)
			this->left->dfs();
		if (this->right)
			this->right->dfs();

	}
	int height()
	{
		//shouldn't need to check for null since it's a class method, couldn't be called on null object
		int leftheight = 0;
		int rightheight = 0;
		if (left != nullptr)
			leftheight = left->height();
		if (right != nullptr)
			rightheight = right->height();
		return (rightheight > leftheight) ? rightheight + 1 : leftheight + 1;
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
	assert(root.find(5) != nullptr);
	assert(root.find(18) == nullptr);
	assert(root.height() == 4);
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
	cout << "Breadth First Search: ";
	root.bfs();
	cout << "Depth First Search: ";
	root.dfs();
	cout << endl;
}