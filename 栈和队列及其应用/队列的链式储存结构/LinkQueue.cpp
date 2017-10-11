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
		Node<T> *s = new Node<T>;
		s->next == NULL;
	}
	else
	{
		Node<T> *s = new Node<T>;
		Node<T> *t = new Node<T>;
		t = front->next;
		s->data = t->data;
		front->next = t->next;
		
		if (t->next == NULL)
		{
			rear = front;
		}
		delete t;
	}
	return T();
}

template<class T>
T LinkQueue<T>::GetQueue()
{
	return T();
}

template<class T>
int LinkQueue<T>::Empty()
{
	return 0;
}
