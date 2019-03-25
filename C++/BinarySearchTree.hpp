#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include "Node.hpp"
#include <vector>
using namespace std;

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
			if (e->key() == key)
			{
				// Remove element
				// Consider two cases:
				// 1. Node to be deleted has one child
				// 2. Node to be deleted has two children
				break;
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
	// TODO:
		4.
		Return the summation of all the keys in the BST falls in the range [left, right] inclusive.
		Print "none" to file if no elements found.
	*/
	int rangeSum(int left, int right)
	{
		vector<int> elements;
		Node<int> *e = rootNode;
		return 0;
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
		return order;
	}

	/*
		7.
		Get the Breadth First or Level order traversal of the BST.
		Use a queue to implement level order
	*/
	void levelorder()
	{
		// If list is empty, print "none"
	}

	/*
		8.
	*/
	int LCA(int key1, int key2)
	{
		return 0;
	}

	// 9. Ceil and 10.Floor

	/*
		11.
	*/
	int dist(int key1, int key2)
	{
		return 0;
	}

	// RB Tree, modify code to handle RB insertion, probably on the other insert
	void insertRB(int key)
	{
		// Refer to DSA book
	}

	/*
		12.
	*/
	int getBlackHeight(int key)
	{
		return 0;
	}
};

#endif // BinarySearchTree_hpp
