#include <iostream>
#include "BiTree.h"
#include "LinkQueue.h"

using namespace std;

int main()
{
	BiTree<char> *A;
	int flag = 0;
	for (; flag == 0;)
	{
		A = new BiTree<char>;
		A->LeafNode();
		cout << endl;
		flag = A->IsEmpty();
		delete A;
	}

	return 0;
}