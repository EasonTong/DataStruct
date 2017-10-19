#pragma once

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
