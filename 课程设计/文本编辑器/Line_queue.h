#include <iostream>

using namespace std;

struct Char_Node
{
	char ch;
	Char_Node *last;
	Char_Node *next;
};

#pragma once
class Line_queue
{
public:
	Line_queue();
	~Line_queue(void);
	Line_queue *last;
	Line_queue *next;
//	int m_Tabs;

	int Input();
	int Length();
	int Diplay_One_Line();

private:
	int m_Length;
	int Pointer;
	Char_Node *pHead;
};

