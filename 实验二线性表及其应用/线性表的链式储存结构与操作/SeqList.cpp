#include <iostream>
#include "SeqList.h"
#include <string>

using namespace std;
//
//SeqList::SeqList()
//{
//}

SeqList::SeqList(int *a, int n)
{
	int i;
	
	if (n > Maxsize)
	{	
		cout << "λ�÷Ƿ�" << endl;
	}
	for (i = 0; i < n; i++)
	{
		Data[i] = a[i];
	}
	length = n;
}


SeqList::~SeqList()
{
}

int SeqList::Get(int i)
{
	
	if (i<1 && i>length)
	{
		cout << "λ�ò���ȷ" << endl;
	}
	else
	{
		return Data[i - 1];
	}
	
}

int SeqList::Loacate(int x)
{
	int i;
	for (i = 0; i < length; i++)
	{
		if (Data[i] == x)
		{
			return i+1;
		}
	}

	return 0;
}

int SeqList::Delete(int i)
{
	int x;
	int j;
	
	if (length == 0)
	{
		cout << "����" << endl;
	}
	if (i<1 || i>length)
	{
		cout << "λ�÷Ƿ�" << endl;
	}
	x = Data[i - 1];
	for (j = i; j < length; j++)
	{
		Data[j - 1] = Data[j];
	}
	length--;
	return x;
}

void SeqList::PrintList()
{
	int i;
	for ( i = 0; i < length; i++)
	{
		cout << Data[i];
	}
}
void SeqList::Insert(int i, int x)
{
	

	int j;
	for (j = length; j >= i; j--)
	{
		Data[j] = Data[j - 1];
	}

	Data[i - 1] = x;
	length++;
}