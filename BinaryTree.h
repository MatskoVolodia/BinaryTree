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
	int GetHeight() const;
	int FrontBypass() const;
	MyType Search(const int _key) const;
	void Show() const;

	friend ostream&operator<<(ostream& os, const BinaryTree<MyType> &ob)
	{
		int height = ob.GetHeight();
		const int blocksize = 2;
		int interval = int(pow(2, height - 1) - 1);  // pow(2,i-1) - count of element in the floor
		int width = int(pow(2, height - 1)*blocksize + (pow(2, height - 1) + 1)*interval); // total width of showing screen.
		int switcher = 0;
		for (int i = 1; i <= height; i++)
		{
			int temp = 1;
			int CountOfElementInFloor = int(pow(2, i - 1));
			interval = (width - CountOfElementInFloor*blocksize) / (CountOfElementInFloor + 1);
			os << string(interval, ' ');
			ShowRecurse(interval, temp, i, ob.root, switcher);
			os << endl;
		}
		return os;
	}

	~BinaryTree();
};

#include "BinaryTree.cpp"
#endif