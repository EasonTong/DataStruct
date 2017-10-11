#include "CirQueue.h"

template<class T>
CirQueue<T>::CirQueue()
{
	rear = MaxSize - 1;
	front = rear;
	JudgeEmpty = 0;
}

template<class T>
CirQueue<T>::~CirQueue()
{
}

template<class T>
void CirQueue<T>::EnQueue(T x)
{
	if ((rear + 1) % MaxSize == front)
	{
		cout << "Queue Full" << endl;
	}
	else
	{
		rear = (rear + 1) % MaxSize;
		Data[rear] = x;
		JudgeEmpty++;
	}
}

template<class T>
T CirQueue<T>::DeQueue()
{
	if (rear == front)
	{
		cout << "None" << endl;
	}
	else
	{
		front = (front + 1)%MaxSize;
		JudgeEmpty--;
		return Data[front];
	}

	return '0';
}

template<class T>
 T CirQueue<T>::GetQueue()
{
	int temp;

	if (rear == front)
	{
		cout << "None" << endl;
	}
	else
	{
		temp = (front + 1) % MaxSize;
		return Data[temp];
	}

	return '0';
}

template<class T>
int CirQueue<T>::Empty()
{
	return JudgeEmpty;
}

template<class T>
void CirQueue<T>::Clear()
{
	front == rear;
	JudgeEmpty = 0;
}

