#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include "Node.hpp"
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// Assume keys are integers and unique
/*
	Note to grading instructor:
		Most of the test cases have different line endings such as "\r\n" or "\n" or even just "\r" (refer to part2input1case2.txt for "postorder")
		The current program will fail some test cases if the lines do not have consistent ending.
		For now, the program will try to match the given output files exactly.
*/
class BinarySearchTree
{
	Node<int> *rootNode;

public:
	BinarySearchTree()
	{
		rootNode = NULL;
	}
	/*
	//
		1.
		A new key is always inserted at a leaf.
		Start searching for a key from the root until we hit a leaf node
		Once a leaf node is found, the new node is added as a child of the leaf node
	*/
	void insertKey(int key)
	{
		// Search for a leaf node. A leaf node is defined as a node that has no children.
		// The first node to be inserted will become the root node
		if (rootNode == NULL)
		{
			rootNode = new Node<int>;
			rootNode->setKey(key);
			rootNode->height = 0; // The root always has a height of zero
			return;
		}

		// Create a new node and set its key
		Node<int> *newNode = new Node<int>;
		newNode->setKey(key);

		Node<int> *e = rootNode; // Provides a mean to traverse the tree

		// TODO: I think I have it so far... Try to implement other methods and
		// we shall see...
		while (e != NULL)
		{
			// Check whether we reached a leaf node
			if (!e->hasChildren())
			{
				// Leaf node is reached because this node has no children
				break;
			}
			if (key < e->key())
			{
				if ((*e).left == NULL) // Edge case
				{
					break;
				}
				e = e->left;
			}
			else if (key > e->key())
			{
				if (e->right == NULL) // Edge case
				{
					break;
				}
				e = e->right;
			}
		}

		// If the while-loop terminates, then we reached a leaf node
		if (key < e->key())
		{
			e->left = newNode;
		}
		else if (key > e->key())
		{
			e->right = newNode;
		}
	}

	/*
		// TODO:
		2.
		Remove the key node from the tree
		If the key is not in the tree, do nothing
	*/
	void deleteKey(int key)
	{
		// Search for a node with the key
		Node<int> *e = rootNode;

		while (e != NULL)
		{
			// Traverse
			if (key < e->key())
			{
				if (e->left->key() == key && e->left != NULL) // Checking whether left node contains our key before setting
				{
					break;
				}
				e = e->left;
			}
			else if (key > e->key())
			{
				if (e->right->key() == key && e->right != NULL) // Checking whether right node contains our key before setting
				{
					break;
				}
				e = e->right;
			}
		}
		// We found a parent node whose child node contains the key
		// Make the child node that contains the key to be NULL
		if (e->left->key() == key)
		{
			e->left = NULL;
		}
		else if (e->right->key() == key)
		{
			e->right = NULL;
		}
	}

	/*
		3. Search for the key in the BST
		Return true if found, otherwise false
	*/
	bool searchKey(int key)
	{
		int h = 0;
		Node<int> *e = rootNode;
		while (e != NULL)
		{
			if (e->key() == key)
			{
				e->height = h;
				return true;
			}
			// Traverse
			if (key < e->key())
			{
				e = e->left;
			}
			else if (key > e->key())
			{
				e = e->right;
			}
			h++;
		}
		return false;
	}

	/*
		4.
		Return the summation of all the keys in the BST falls in the range [left, right] inclusive.
		Print "none" to file if no elements found.
	*/
	int rangeSum(int left, int right)
	{
		int sum = 0;
		vector<int> elements = postorder();
		vector<int> keys;
		for (auto key : elements) {
			if (left <= key && key <= right)
			{
				keys.push_back(key);
			}
		}
		for (auto key : keys) {
			sum += key;
		}
		return sum;
	}

	/*
		5.
	*/
	int height(int key)
	{
		Node<int> *e = rootNode;
		while (e != NULL)
		{
			if (e->key() == key) {
				return e->height;
			}
			// Traverse
			if (key < e->key())
			{
				e = e->left;
			}
			else if (key > e->key())
			{
				e = e->right;
			}
		}
		return 0;
	}

	/*
		6.
		Get the postorder traversal of the BST.
	*/
	vector<int> postorder()
	{
		// If list is empty, print "none"
		vector<int> order;
		stack<Node<int>*> nodes;

		if (rootNode == NULL)
		{
			return order; // The list is empty
		}

		nodes.push(rootNode);

		while (!nodes.empty())
		{
			Node<int> *e = nodes.top();
			nodes.pop();
			order.insert(order.begin(), e->key());
			if (e->left)
			{
				nodes.push(e->left);
			}
			if (e->right)
			{
				nodes.push(e->right);
			}
		}
		
		return order;
	}

	/*
		7. TODO:
		Get the Breadth First or Level order traversal of the BST.
		Use a queue to implement level order
	*/
	vector<int> levelorder()
	{
		// If list is empty, print "none"
		vector<int> order;
		queue<Node<int>*> nodes;

		if (rootNode == NULL) {
			return order;
		}

		nodes.push(rootNode);

		while (!nodes.empty())
		{
			Node<int> *e = nodes.front();
			order.push_back(e->key()); // The order is reversed. So we need to push back instead of inserting to front..
			nodes.pop();

			if (e->left)
			{
				nodes.push(e->left);
			}
			if (e->right)
			{
				nodes.push(e->right);
			}
		}

		return order;
	}

	/*
		8. TODO:
	*/
	int LCA(int key1, int key2)
	{
		return 0;
	}

	// 9. Ceil TODO:
	int ceil()
	{
		return 0;
	}

	// 10. Floor TODO:
	int floor() {
		return 0;
	}

	/*
		11. TODO:
	*/
	int dist(int key1, int key2)
	{
		return 0;
	}

	// TODO:
	void insertRB(int key)
	{
		// Refer to DSA book
	}

	/*
		12. TODO:
	*/
	int getBlackHeight(int key)
	{
		return 0;
	}
};

#endif // BinarySearchTree_hpp
