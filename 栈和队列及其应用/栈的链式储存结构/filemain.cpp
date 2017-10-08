#include <iostream>

using namespace std;


struct Node
{
	char data;
	Node *next;
};

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
	Node *top;
};

int main()
{
	char flag = 'e';
	char x;
	LinkStack<char> A;

	while (flag!='E')
	{
		cin >> flag;

		if (flag=='P')
		{
			cin >> x;
			A.Push(x);
		}

		if (flag == 'D')
		{
			x = A.Pop();
			if (x == '0')
			{
				cout << "None" << endl;
			} 
			else
			{
				cout << x << endl;
			}
		}

		if (flag == 'G')
		{
			x = A.GetTop();
			if (x == '0')
			{
				cout << "None" << endl;
			}
			else
			{
				cout << x << endl;
			}
		}

		if (flag == 'T')
		{
			A.~LinkStack();
		}

		if (flag == 'Y')
		{
			x = A.Empty();

			if (x == 1)
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
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
	Node *s = new Node;
	s->data = x;
	s->next = top;
	top = s;
}

template <class T>
T LinkStack<T>::Pop()
{
	if (top==NULL)
	{
		return '0';
	}
	else
	{
		int x;
		x = top->data;
		top = top->next;
		return x;
	}

}

template <class T>
T LinkStack<T>::GetTop()
{
	if (top==NULL)
	{
		return '0';
	} 
	else
	{
		return top->data;
	}
	
}

template <class T>
int LinkStack<T>::Empty()
{
	if (top==NULL)
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
	Node *p,*q;
	if (top != NULL)
	{
		//如果top都是空的，就没必要释放
		q = top;
		p = top->next;
		
		while (p!=NULL)
		{
			delete q;
			q = p;
			p = p->next;
		}
		delete q;
	}

	top = NULL;
}