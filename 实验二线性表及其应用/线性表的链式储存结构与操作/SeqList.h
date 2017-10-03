#pragma once
const int Maxsize = 100;
class SeqList
{
public:
	SeqList()
	{
		length = 0;
	}
	SeqList(int *a, int n);
	~SeqList();
	int Length()
	{
		return length;
	}
	int Get(int n);
	int Loacate(int x);
	void Insert(int i, int x);
	int Delete(int i);
	void PrintList();

private:
	int Data[Maxsize];
	int length;
};

