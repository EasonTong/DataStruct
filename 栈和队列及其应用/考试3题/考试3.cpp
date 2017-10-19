//注意最后的yes和no不大写，不能有空格
#include <iostream>
#include <string>

using namespace std;

struct MyStruct
{
	char x;
	int Poz;
};

struct MyStruct1
{
	int x;
	int y;
};



template <class T>
struct Node
{
	T data;
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
	Node<T> *front;
	Node<T> *rear;
};

//#include "LinkQueue.h"


template <class T>
class LinkStack
{
public:
	LinkStack();
	~LinkStack();
	void Push(T x);
	T Pop();
	T GetTop();
	int Empty();
private:
	Node<T> *top;
};

int main()
{
	string A;
	int flag = 0;
	LinkStack<MyStruct> B;
	//LinkStack<MyStruct1> Result;
	LinkQueue<MyStruct1> Result;
	cin >> A;
	int i;
//	char x;
	MyStruct Z;
	MyStruct1 X;
	int count = 0;

	for (i = 0; i < A.length(); i++)
	{
		if (A[i] == '{' || A[i] == '(' || A[i] == '[')
		{
			Z.x = A[i];
			Z.Poz = i;
			B.Push(Z);
			count++;
		}
		else
		{
			Z = B.GetTop();

			if (Z.x == '(' && A[i] == ')')
			{
				B.Pop();
				X.x = Z.Poz;
				X.y = i;
				Result.EnQueue(X);
			}
			else if (Z.x == '{' && A[i] == '}')
			{
				B.Pop();
				X.x = Z.Poz;
				X.y = i;
				Result.EnQueue(X);
			}
			else if (Z.x == '[' && A[i] == ']')
			{
				B.Pop();
				X.x = Z.Poz;
				X.y = i;
				Result.EnQueue(X);
			}
			else
			{
				//cout << "no" << endl;
				cout << "Wrong";
				flag = 1;
				break;

			}
		}
	}

	if (flag == 0)
	{
		//cout << "yes" << endl;
		//cout << "yes";
		for (i = 0; i < count; i++)
		{
			X = Result.DeQueue();
			cout << "(" << X.x << "," << X.y << ")";
		}
	}

	return 0;
}

template <class T>
LinkStack<T>::LinkStack()
{
	top = NULL;
}

template <class T>
void LinkStack<T>::Push(T x)
{
	Node<T> *s = new Node<T>;
	s->data = x;
	s->next = top;
	top = s;
}

template <class T>
T LinkStack<T>::Pop()
{
	if (top == NULL)
	{
		//对于不同的类型，此处需要修改
		//
		T x;
		
		return x;
	}
	else
	{
		T x;
		x = top->data;
		top = top->next;
		return x;
	}

}

template <class T>
T LinkStack<T>::GetTop()
{
	if (top == NULL)
	{
		//对于不同的类型，此处需要修改
		//

		T x;
		return x;
	}
	else
	{
		return top->data;
	}

}

template <class T>
int LinkStack<T>::Empty()
{
	if (top == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template <class T>
LinkStack<T>::~LinkStack()
{
	Node<T> *p, *q;
	if (top != NULL)
	{
		//如果top都是空的，就没必要释放
		q = top;
		p = top->next;

		while (p != NULL)
		{
			delete q;
			q = p;
			p = p->next;
		}
		delete q;
	}

	top = NULL;
}





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
	s->data = x;
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
		cout << "下溢" << endl;
		//T s;
		//s = '\0';
	}
	else
	{
		//T s;
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
	Node *p;
	T s;
	if (front == rear)
	{
		cout << "下溢" << endl;
		//s = '\0';
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
	Node *p;
	while (front->next != NULL)
	{
		p = front;
		front = front->next;
		delete p;
	}

	rear = front;
}