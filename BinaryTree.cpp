#ifndef BINARYTREE_CPP
#define BINARYTREE_CPP

#include "BinaryTree.h"
#include "RecurseFunctions.cpp"
#include <iomanip>

template <class MyType = int>
BinaryTree<MyType>::BinaryTree()
{
	root = nullptr;
}

template <class MyType = int>
void BinaryTree<MyType>::Push(MyType _data, int _key)
{
	if (root == nullptr)
	{
		root = new TreeItem<MyType>(_data, _key);
		return;
	}

	PushItem(_data, _key, root);
}

template <class MyType = int>
int BinaryTree<MyType>::GetHeight()
{
	if (root == nullptr) return 0;
	int temp = 1; int max = 1;
	HeightRecurse(temp, max, root);
	return max;
}

template <class MyType = int>
void BinaryTree<MyType>::LeftBypass()
{
	LBypass(root);
}

/*
template <class MyType = int>
ostream&operator<<(ostream& os, const BinaryTree<MyType> &ob)
{
	int height = ob.GetHeight();
	const int blocksize = 5;
	int interval = pow(2, height) - 1;
	for (int i = 0; i < height; i++)
	{

	}

	return os;
}
*/

template <class MyType = int>
BinaryTree<MyType>::~BinaryTree()
{
	root = nullptr;
}

#endif