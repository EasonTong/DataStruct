#pragma once
#include <iostream>
#include "Line_queue.h"

using namespace std;

class Page_queue
{
public:
	Page_queue(void);
	~Page_queue(void);
	void Input_Line();
	void Display_Page(int Start);

private:
	Line_queue *pHead;
	int Display_Start;
	int Display_End;
	int Pointer_Line;
};

