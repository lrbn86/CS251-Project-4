#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include "Node.hpp"
#include <vector>
using namespace std;

class BinarySearchTree
{
	// TODO:
	Node<int> *root = new Node<int>; // Allocate
	// Bus error due to Undefined Behavior.. Need to allocate first.

public:
	BinarySearchTree() {}
	/*
	// TODO:
		1.
		A new key is always inserted at a leaf.
		Start searching for a key from the root until we hit a leaf node
		Once a leaf node is found, the new node is added as a child of the leaf node
	*/
	void insertKey(int key)
	{
		(*root).setKey(key);
		(*root).printKey();
	}

	/*
		// TODO:
		2.
		Remove the key node from the tree
		If the key is not in the tree, do nothing
	*/
	void deleteKey(int key)
	{
	}

	/*
		3. Search for the key in the BST
		Return true if found, otherwise false
	*/
	bool searchKey(int key)
	{
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
		return 0;
	}

	/*
	// TODO:
		5.
	*/
	int height(int key)
	{
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
