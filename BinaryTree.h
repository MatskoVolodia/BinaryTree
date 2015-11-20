#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
using namespace std;

template <class MyType = int>
struct TreeItem
{
	MyType data;
	int key;
	TreeItem* right;
	TreeItem* left;
	
	TreeItem(MyType _data, int _key)
	{
		data = _data;
		key = _key;
		right = nullptr;
		left = nullptr;
	}
};

template <class MyType = int>
class BinaryTree
{
protected:
	TreeItem<MyType> *root;
public:
	BinaryTree();
	void Push(MyType _data, int _key);
	int GetHeight();
	void LeftBypass();
	//friend ostream&operator<<(ostream&os, const BinaryTree &ob);
	~BinaryTree();
};

#include "BinaryTree.cpp"
#endif