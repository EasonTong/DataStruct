#pragma once

template <class T>
struct Node
{
	T Data;
	Node *next;
};

template <class T>
class LinkQueue
{
public:
	LinkQueue();
	virtual ~LinkQueue();
	void EnQueue(T x);
	Node<T>* DeQueue();
	Node<T>* GetQueue();
	int Empty();
	void GetClean();

private:
	Node<T> *front;
	Node<T> *rear;
};

//#include "LinkQueue.h"


template <class T>
LinkQueue<T>::LinkQueue()
{
	Node<T> *s = new Node<T>;
	s->next = NULL;
	front = s;
	rear = s;
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
	s->Data = x;
	s->next = NULL;
	rear->next = s;
	rear = s;
}

template<class T>
Node<T>* LinkQueue<T>::DeQueue()
{
	Node<T> *s = new Node<T>;
	if (rear == front)
	{
		cout << "ÏÂÒç" << endl;
		//T s;
		return NULL;
	}
	else
	{
		//T s;
		Node<T> *t;
		t = front->next;
		s->Data = t->Data;
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
Node<T>* LinkQueue<T>::GetQueue()
{
	Node<T> *p;
	Node<T> *s = new Node<T>;
	if (front == rear)
	{
		cout << "ÏÂÒç" << endl;
		return NULL;
	}
	else
	{
		p = front->next;
		s->Data = p->Data;
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