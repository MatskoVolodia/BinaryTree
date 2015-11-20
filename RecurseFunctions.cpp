#ifndef RECURSEFUNCTIONS_CPP
#define RECURSEFUNCTIONS_CPP

#include "BinaryTree.h"

template <class MyType = int>
void PushItem(MyType _data, int _key, TreeItem<MyType>* &current)
{
	if (current == nullptr)
	{
		current = new TreeItem<MyType>(_data, _key);
		return;
	}
	if (current->key < _key)
	{
		PushItem(_data, _key, current->right);
	}
	if (current->key > _key)
	{
		PushItem(_data, _key, current->left);
	}
}

template <class MyType = int>
void HeightRecurse(int &temp, int &max, TreeItem<MyType>* &current)
{
	if ((current->left == nullptr) && (current->right == nullptr))
	{
		max = (temp > max) ? temp : max;
		temp--;
		return;
	}
	if (current->left != nullptr) HeightRecurse(++temp, max, current->left);
	if (current->right != nullptr) HeightRecurse(++temp, max, current->right);
	--temp;
}

template <class MyType = int>
void LBypass(const TreeItem<MyType>* current)
{
	if ((current->left == nullptr) && (current->right == nullptr))
	{
		cout << current->key << endl;
		return;
	}
	if (current->left != nullptr) LBypass(current->left);
	if (current->right != nullptr) LBypass(current->right);
}

/*
template <class MyType = int>
void ShowRecurse(int &temp, const int limit, const TreeItem<MyType>* &current)
{
	while (temp > limit)
	{
		if (current->left != nullptr) ShowRecurse(++temp, max, current->left);
	}
	if (current->right != nullptr) ShowRecurse(++temp, max, current->right);
	--temp;
}
*/
#endif