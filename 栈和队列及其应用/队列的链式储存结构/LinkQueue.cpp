#include "LinkQueue.h"


template <class T>
LinkQueue<T>::LinkQueue()
{
	Node<T> *s = new Node<T>;
	s->data = NULL;
	front = s;
	s = rear;
}

template <class T>
LinkQueue<T>::~LinkQueue()
{
	Node<T> *p;
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
	Node<T> *s = new Node<T>;
	s->data = x;
	s->next = NULL;
	rear->next = s;
	rear = s;
}

template<class T>
T LinkQueue<T>::DeQueue()
{
	if (rear == front)
	{
		cout << "ÏÂÒç" << endl;
		T s;
		s = '\0';
	}
	else
	{
		T s;
		Node<T> *t;
		t = front->next;
		s = t->data;
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
	Node<T> *p;
	T s;
	if (front == rear)
	{
		cout << "ÏÂÒç" << endl;
		s = '\0';
	}
	else
	{
		p = front->next;
		s = p->data;
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
	Node<T> *p;
	while (front->next != NULL)
	{
		p = front;
		front = front->next;
		delete p;
	}

	rear = front;
}