#include <iostream>
#include "LinkQueue.h"
//#include "LinkQueue.cpp"
using namespace std;


//template<T> class LinkQueue;

int main()
{
	//Node<char> M;
	//cout << "Hello World" << endl;
	char x;
	Node temp;
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