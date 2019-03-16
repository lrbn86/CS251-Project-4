#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

using namespace std;

class BinarySearchTree
{
	// TODO:
	Node *root;

public:
	/*
		1. A new key is always inserted at a leaf.
		Start searching for a key from the root until we hit a leaf node
		Once a leaf node is found, the new node is added as a child of the leaf node
	*/
	void insertKey(int key)
	{
	}

	/*
		2. Remove the key node from the tree
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
		4.
	*/
	int rangeSum(int left, int right)
	{
		return 0;
	}

	/*
		5.
	*/
	int height(int key)
	{
		return 0;
	}

	/*
		6.
	*/
	void postorder()
	{
	}

	/*
		7.
	*/
	void levelorder()
	{
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

	}
};

#endif // BinarySearchTree_hpp
