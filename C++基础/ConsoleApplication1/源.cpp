#include <iostream>
using namespace std;

template <class DataType>
class Node
{
public:
	int value;
	Node *next;
};

template <class DataType>
class LinkList
{
public:
	LinkList();
	LinkList(int a[], int n);
	~LinkList();
	int Length();
	void Get(int i);
	void Locate(int x);
	void Insert(int i, int x);
	void Delete(int i);
	void PrintList();
private:
	Node<DataType> *first;
};

template <class DataType>
void LinkList<DataType>::PrintList()
{
	p = first->next;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}
}

template <class DataType>
int LinkList<DataType>::Length()
{
	p = first->next;
	count = 0;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}

	cout << count << endl;
}

template <class DataType>
void LinkList<DataType>::Get(int i)
{
	p = first->next;
	count = 1;
	while (p != NULL && count < i)
	{
		p = p->next;
		count++;
	}
	if (p == NULL)
	{
		cout << "位置不正确" << endl;
	}
	else
	{
		cout << p->data << endl;
	}
}

template <class DataType>
void LinkList<DataType>::Locate(int x)
{
	p = first->next;
	count = 1;
	while (p != NULL)
	{
		if (p->data == x)
		{
			cout << count << endl;
			return;
		}
		p = p->next;
		count++;
	}
	cout << "None" << endl;
}

template <class DataType>
void LinkList<DataType>::Insert(int i, int x)
{
	p = first;
	count = 0;
	while (p != NULL && count < i - 1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL)
	{
		cout << "位置不正确" << endl;
	}
	else
	{
		s = new Node;
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
}

template <class DataType>
LinkList<DataType>::LinkList()
{
	first = new Node;
	first->next = NULL;
}

template <class DataType>
void LinkList<DataType>::Delete(int i)
{
	p = first;
	count = 0;
	while (p != NULL && count < i - 1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL || p->next == NULL)
	{
		cout << "位置不正确" << endl;
	}
	else
	{
		q = p->next;
		x = q->data;
		p->next = q->next;
		delete q;
		return x;
	}
}

template <class DataType>
LinkList<DataType>::~LinkList()
{
	while (first != NULL)
	{
		q = first;
		first = first->next;
		delete q;
	}
}

//template <class DataType>
int main()
{
	char state;
	LinkList<int> l;
	while (1)
	{
		cin >> state;
		if (state == 'I')
		{
			int n;
			int j;
			int index;
			int num;
			cin >> n;
			for (j = 0; j < n; j++)
			{
				cin >> index;
				cin >> num;
				//	l.Insert(index, num);
			}
		}
		if (state == 'S')
		{
			int num;
			cin >> num;
			l.Locate(num);
		}
		if (state == 'G')
		{
			int index;
			cin >> index;
			l.Get(index);
		}
		if (state == 'D')
		{
			int index;
			cin >> index;
			l.Delete(index);
		}
		if (state == 'L')
		{
			l.Length();
		}
		if (state == 'V')
		{
			l.PrintList();
		}
		if (state == 'E')
		{
			break;
		}
	}

	return 0;
}