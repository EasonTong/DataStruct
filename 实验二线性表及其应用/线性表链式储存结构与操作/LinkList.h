// LinkList.h: interface for the LinkList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINKLIST_H__598A223A_A794_4E57_AFF1_270188E681A2__INCLUDED_)
#define AFX_LINKLIST_H__598A223A_A794_4E57_AFF1_270188E681A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct Node
{
	int data;
	Node *next;
};

class LinkList  
{
public:
	LinkList();
	virtual ~LinkList();
	LinkList(int *a, int n);
	int Length();
	int Get(int i);
	int Locate(int x);
	void Insert(int i, int x);
	int Delete(int i);
	void PrintList();
private:
	Node *first;

};

#endif // !defined(AFX_LINKLIST_H__598A223A_A794_4E57_AFF1_270188E681A2__INCLUDED_)
