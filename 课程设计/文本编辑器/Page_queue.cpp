#include <iostream>
#include "Page_queue.h"
#include "Line_queue.h"

const int FULL_Dispaly = 10;

using namespace std;

Page_queue::Page_queue(void)
{
	pHead = new Line_queue;
	pHead->last = NULL;
	pHead->next = NULL;
	Pointer_Line = 0;
	Display_Start = 0;
	Display_End = 0;
}


Page_queue::~Page_queue(void)
{
}

void Page_queue::Input_Line()
{
	int flag = -1;
	Line_queue *pTemp_Line,  *pTemp_Line1;
	
	
	pTemp_Line = pHead;

	//找到合适的编辑位置
	for (int i=0; i<Pointer_Line; i++)
	{
		pTemp_Line=pTemp_Line->next;
	}

	//开始编辑
	while (flag!=3)
	{
		flag = pTemp_Line->Input();
		

		if (flag == 1)
		{//这里注意还需要插入行
			pTemp_Line1 = new Line_queue;
			pTemp_Line1->last = pTemp_Line;
			pTemp_Line1->next = pTemp_Line->next;
			pTemp_Line->next = pTemp_Line1;

			//指针切换到下一行
			pTemp_Line = pTemp_Line1;
			Display_End++;
		}
		if (flag == 2)
		{
			cout << "sad";
			if(pTemp_Line != pHead)
			{	//这里有问题
				pTemp_Line1 = pTemp_Line;
				pTemp_Line = pTemp_Line->last;//此处还有些小问题，之后还需要修改，但是还没有明确具体问题是什么
				//防止最开始的清除造成内存报错
				pTemp_Line->next = pTemp_Line1->next;

				if (pTemp_Line1->next!=NULL)
				{
					pTemp_Line1->next->last = pTemp_Line1;
				}
//				delete pTemp_Line1;// 神他妈这里内存报错
				
				Display_End--;//没办法真能用这样的土办法
			}	
		}
		this->Display_Page(0);//日后修改,display line pozition
	}
	
}

void Page_queue::Display_Page(int Display_Start)
{
	Line_queue *pTemp_Display;
	pTemp_Display = pHead;

	int counter=0;//控制总输出为20行
	int count_Line=0;//计算总行数
	int count_all_char=0;//计算总字符数

	system("cls");
	//找到合适的显示开始位置
	for (int i=0; i<Display_Start; i++)
	{
		pTemp_Display = pTemp_Display->next;
		count_Line++;
	}

	while(pTemp_Display!=NULL && counter < FULL_Dispaly)
	{
		counter++;
		count_all_char += pTemp_Display->Diplay_One_Line();
		count_Line++;
		cout << endl;
		pTemp_Display = pTemp_Display->next;
	}

	while(counter<=FULL_Dispaly)
	{
		cout << endl;
		counter++;
	}

	//command bar 

	cout << "Sum Line	" << count_Line << "	Sum char	" << count_all_char;
}
