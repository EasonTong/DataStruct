#pragma once

const int MaxSize = 100;

template <class T>
class CirQueue
{
public:
	CirQueue();
	virtual ~CirQueue();
	void EnQueue(T x);
	T DeQueue();
	T GetQueue();
	int Empty();
	void Clear();
private:
	T Data[MaxSize];
	int front;
	int rear;
	int JudgeEmpty;
};

