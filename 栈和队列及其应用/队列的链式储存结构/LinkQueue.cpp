#include "LinkQueue.h"


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
		cout << "����" << endl;
		//������Ҫ���������޸�
		//T s;
		//s = '\0';
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
		cout << "����" << endl;
		//s = '\0';
		//������Ҫ�����������
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