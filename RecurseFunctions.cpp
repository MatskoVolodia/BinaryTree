#ifndef RECURSEFUNCTIONS_CPP
#define RECURSEFUNCTIONS_CPP

#include <iostream>
#include "BinaryTree.h"
#include <Windows.h>
#include <string>
using namespace std;

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
void HeightRecurse(int &temp, int &max, TreeItem<MyType>* current)
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
void ShowRecurse(const int interval, int &temp, const int limit, const TreeItem<MyType>* current, int &switcher)   // Show only a limit floor
{
	if (((current->left == nullptr) && (current->right == nullptr)) || (temp == limit))
	{
		if (temp == limit)
		{
			SetColor(switcher);
			cout << current->key << string(interval, ' ');
		}
		temp--;
		return;
	}
	if (current->left != nullptr) ShowRecurse(interval, ++temp, limit, current->left, switcher);
	if (current->right != nullptr) ShowRecurse(interval, ++temp, limit, current->right, switcher);
	--temp;
}

template <class MyType = int>
void FBypass(const TreeItem<MyType>* current) 
{
	cout << "Data: " << current->data << endl;
	cout << "Key : " << current->key << endl;
	cout << "---\n";
	if ((current->left == nullptr) && (current->right == nullptr))
	{
		return;
	}
	if (current->left != nullptr) FBypass(current->left);
	if (current->right != nullptr) FBypass(current->right);
}

// a few needed not recurse functions

inline bool isOdd(int integer)
{

	if (integer % 2 == 0)
		return false;
	else
		return true;
}

inline void SetColor(int &switcher)
{
	if (switcher == 0)
	{
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdOut, (WORD)(0 << 4 | 4));
		switcher++;
	}
 else
 {
	 if (isOdd(switcher))
	 {
		 HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		 SetConsoleTextAttribute(hStdOut, (WORD)(0 << 4 | (1+switcher > 15) ? switcher - 14 : 1+switcher));
		 switcher++;
	 } else
	 if (!isOdd(switcher))
	 {
		 switcher++;
	 }
 }
}


#endif