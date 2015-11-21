#include <iostream>
#include <fstream>

#include "BinaryTree.h"
#include "RecurseFunctions.cpp"

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
	
	tree.FrontBypass();

	//cout << tree;
	//tree.Show();
	//cout << tree.Search(8) << endl;
	//cout << tree.GetHeight() << endl;
	DataFile.close();
	system("pause");
	return 0;
}