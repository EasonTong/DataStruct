#include <iostream>
#include "MGraph.h"

using namespace std;

int main()
{
	int n,e,i;
	cin >> n >> e;
	char ch[100];
	for (i=0; i<n; i++)
	{
		cin >> ch[i];
	}

	MGraph<char> A(ch, n, e);

	for (i=0; i<n; i++)
	{
		cout << ch[i] << " ";
	}
	cout << endl;

	A.PrintMatrix();
	A.DFST();
	cout << endl;
	A.BFST();

	return 0;
}