// LinkList.cpp: implementation of the LinkList class.
//
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include "LinkList.h"

using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

LinkList::LinkList()
{
	first = new Node;
	first->next = NULL;
}

LinkList::LinkList(int *a, int n)
{
	Node *r,*s;
	first = new Node;
	int i;
	r = first;
	for(i=0; i<n; i++)
	{
		s = new Node;
		s ->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

LinkList::~LinkList()
{
	Node *q;
	while (first!=NULL)
	{
		q = first;
		first = first->next;
		delete q;
	}
}

void LinkList::PrintList()
{
	Node *p;
	p = first->next;
	while(p!=NULL)
	{
		cout << p ->data << endl;
		p = p ->next;
	}
}

int LinkList::Length()
{
	int count=0;
	Node *p = first ->next;

	while(p!=NULL)
	{
		p=p->next;
		count++;
	}
	
	return count;
}

int LinkList::Get(int i)
{
	Node *p = first ->next;
	int count = 1;

	while (p!=NULL && count < i)
	{
		p = p ->next;
		count++;
	}
	if (p==NULL)
	{
		return -1;
	}
	else
	{
		return p->data;
	}
}

int LinkList::Locate(int x)
{
	Node *p = first ->next;
	int count = 1;

	while (p!=NULL)
	{
		if (p->data == x)
		{
			return count;
		}
		
		p = p ->next;
		count++;
	}

	return 0;
}

void LinkList::Insert(int i, int x)
{
	Node *p = first;
	int count = 0;
	
	while (p!=NULL && count < i-1)
	{
		p = p ->next;
		count++;
	}

	if (p==NULL)
	{
		//char *s = "位置";
		//throw s;
		cout << "位置不正确" << endl;
	}
	else 
	{
		Node *s = new Node;
		s ->data = x;
		s ->next = p ->next;
		p ->next = s;
	}
}

int LinkList::Delete(int i)
{
	Node *p = first;
	Node *q;
	int count = 0;
	int x;

	while (p!=NULL && count < i-1)
	{
		p = p->next;
		count++;
	}

	if (p==NULL || p->next==NULL)
	{
		/*char *s = "位置";
		throw s;*/
		cout << "位置" << endl;
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
