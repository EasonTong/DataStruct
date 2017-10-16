#include <iostream>
//#include "LinkQueue.h"
using namespace std;



struct Node
{
	char Data;
	Node *next;
};

template <class T>
class LinkQueue
{
public:
	LinkQueue();
	virtual ~LinkQueue();
	void EnQueue(T x);
	T DeQueue();
	T GetQueue();
	int Empty();
	void GetClean();

private:
	Node *front;
	Node *rear;
};


template <class T>
LinkQueue<T>::LinkQueue()
{
	Node *s = new Node;
	s->next = NULL;
	front = s;
	rear = s;
}

template <class T>
LinkQueue<T>::~LinkQueue()
{
	Node *p;
	while (front != NULL)
	{
		p = front;
		front = front->next;
		delete p;
	}
}

template<class T>
void LinkQueue<T>::EnQueue(T x)
{
	Node *s = new Node;
	s->Data = x;
	s->next = NULL;
	rear->next = s;
	rear = s;
}

template<class T>
T LinkQueue<T>::DeQueue()
{
	T s;
	if (rear == front)
	{
		cout << "None" << endl;
		//T s;
		s = '\0';
	}
	else
	{
		//T s;
		Node *t;
		t = front->next;
		s = t->Data;
		front->next = t->next;

		if (t->next == NULL)
		{
			rear = front;
		}
		delete t;
	}
	return s;

}

template<class T>
T LinkQueue<T>::GetQueue()
{
	Node *p;
	T s;
	if (front == rear)
	{
		cout << "None" << endl;
		s = '\0';
	}
	else
	{
		p = front->next;
		s = p->Data;
	}

	return s;
}

template<class T>
int LinkQueue<T>::Empty()
{
	if (front == rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template<class T>
void LinkQueue<T>::GetClean()
{
	Node *p;
	while (front->next != NULL)
	{
		p = front;
		front = front->next;
		delete p;
	}

	rear = front;
}
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