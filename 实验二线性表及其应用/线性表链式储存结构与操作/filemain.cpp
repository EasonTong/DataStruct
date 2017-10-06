//线性表的链式存储结构与操作
//链表
#include <iostream>
#include "LinkList.h"
using namespace std;

int main()
{
	int n;
	//int a[100];
	char flag = 'a';
	int i;
	LinkList b;
	int temp1, temp2;

	for (; flag != 'E';)
	{
		cin >> flag;

		if (flag == 'I')
		{
			cin >> n;
			for (i = 0; i < n; i++)
			{
				cin >> temp1;
				cin >> temp2;
				b.Insert(temp1, temp2);
			}
		}

		if (flag == 'S')
		{
			cin >> temp1;
			temp2 = b.Locate(temp1);

			if (temp2 == 0)
			{
				cout << "None" << endl;
			}
			else
			{
				cout << temp2 << endl;
			}

		}

		if (flag == 'G')
		{
			cin >> temp1;
			temp2 = b.Get(temp1);
			cout << temp2 << endl;
		}

		if (flag == 'V')
		{
			b.PrintList();
		}

		if (flag == 'D')
		{
			cin >> temp1;

			if ((temp2 = b.Delete(temp1)) != 0)
			{
				cout << temp2 << endl;
			}

		}

		if (flag == 'L')
		{
			cout << b.Length() << endl;
		}
	}

	return 0;
}