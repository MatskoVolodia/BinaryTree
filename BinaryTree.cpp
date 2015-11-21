#ifndef BINARYTREE_CPP
#define BINARYTREE_CPP

#include "BinaryTree.h"
#include "RecurseFunctions.cpp"
#include <iomanip>
#include <string>

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
int BinaryTree<MyType>::GetHeight() const
{
	if (root == nullptr) return 0;
	int temp = 1; int max = 1;
	HeightRecurse(temp, max, root);
	return max;
}

template <class MyType = int>
int BinaryTree<MyType>::FrontBypass() const 
{
	if (root == nullptr) return 0;
	FBypass(root);
	return 1;
}

template <class MyType = int>
MyType BinaryTree<MyType>::Search(const int _key) const
{
	if (root == nullptr)
	{
		cout << "Tree is empty.\n";
		return NULL;
	}
	TreeItem<MyType>* temp;
	temp = root;
	while (temp != nullptr)
	{
		if (temp->key == _key)
		{
			return temp->data;
		}
		if (temp->key > _key) temp = temp->left;
		if (temp->key < _key) temp = temp->right;
	}
	cout << "Element hasn't found. Returned root data.\n";
	return root->data;
}

template <class MyType = int>
void BinaryTree<MyType>::Show() const
{
	int height = GetHeight();
	const int blocksize = 2;
	int interval = int(pow(2, height - 1) - 1);  // pow(2,i-1) - count of element in the floor
	int width = int(pow(2, height - 1)*blocksize + (pow(2,height-1)+1)*interval); // total width of showing screen.
	int switcher = 0;
	for (int i = 1; i <= height; i++)
	{
		int temp = 1;
		int CountOfElementInFloor = int(pow(2, i - 1));
		interval = (width - CountOfElementInFloor*blocksize) / (CountOfElementInFloor+1);
		cout << string(interval, ' ');
		ShowRecurse(interval, temp, i, root, switcher);
		cout << endl;
	}
}

template <class MyType = int>
BinaryTree<MyType>::~BinaryTree()
{
	root = nullptr;
}

#endif