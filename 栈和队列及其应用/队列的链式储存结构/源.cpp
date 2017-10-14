#include <iostream>
#include "LinkQueue.h"

using namespace std;

template <class T>
struct Node
{
	T Data;
	Node<T> *next;
};

int main()
{
	//Node<char> M;
	//cout << "Hello World" << endl;
	char x;
	Node<char> temp;
	char flag = 'e';
	LinkQueue<char> A;

	while (flag != 'Q')
	{
		cin >> flag;

		if (flag == 'E')
		{
			//Èë¶Ó
			cin >> x;
			A.EnQueue(x);
		}

		if (flag == 'C')
		{
			A.GetClean();
		}

		if (flag == 'G')
		{
			x = A.GetQueue();
			if (x != '\0')
			{
				cout << x << endl;
			}
		}

		if (flag == 'D')
		{
			x = A.DeQueue();
			if (x != '\0')
			{
				cout << x << endl;
			}
		}
	}



	return 0;
}