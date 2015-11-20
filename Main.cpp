#include <iostream>
#include <fstream>

#include "BinaryTree.h"

using namespace std;

int main()
{
	ifstream DataFile; DataFile.open("Data.txt");

	BinaryTree<int> tree;
	while (DataFile)
	{
		int data; int key;
		DataFile >> data;
		DataFile >> key;
		tree.Push(data, key);
	}

	tree.LeftBypass();
	//cout << tree.GetHeight() << endl;
	DataFile.close();
	system("pause");
	return 0;
}