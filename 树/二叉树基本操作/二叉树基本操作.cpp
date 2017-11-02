#include <iostream>
#include "BiTree.h"
#include "LinkQueue.h"
using namespace std;

int main()
{
	BiTree<int> A;
	A.PreOrder();
	cout << endl;
	A.InOrder();
	cout << endl;
	A.PostOrder();
	cout << endl;
	A.LeverOrder();
	cout << endl;

	return 0;
}