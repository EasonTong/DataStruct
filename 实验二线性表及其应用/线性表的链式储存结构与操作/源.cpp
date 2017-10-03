#include <iostream>
#include "SeqList.h"
using namespace std;

int main()
{
	int n;
	//int a[100];
	char flag='a';
	int i;
	SeqList b;
	int tmp1, tmp2;

	cout << "hello world";

	for (; flag != 'E';)
	{
		cin >> flag;

		if (flag == 'I')
		{
			cin >> n;
			for (i = 0; i < n; i++)
			{
				cin >> tmp1;
				cin >> tmp2;
				b.Insert(tmp1, tmp2);
			}
		}

		if (flag == 'S')
		{
			cin >> tmp1;
			tmp2 = b.Loacate(tmp1);
			
			if (tmp2 == 0)
			{
				cout << "None" << endl;
			}
			else
			{
				cout << tmp2 << endl;
			}
			
		}

		if (flag == 'G')
		{
			cin >> tmp1;
			tmp2 = b.Get(tmp1);
		}
	}

	return 0;
}