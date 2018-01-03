#include <conio.h>
#include "Line_queue.h"


Line_queue::Line_queue(void)
{
	pHead = new Char_Node;
	pHead->next = NULL;//字符头结点初始化
	pHead->last = NULL;
//	m_Tabs = 0;
	Pointer=0;
}


Line_queue::~Line_queue(void)
{
	//析构函数
	Char_Node *p_next = pHead;
	while(p_next!=NULL)
	{
		p_next = pHead;
		delete p_next;
		pHead = pHead->next;
	}
}


//返回值为3时是手动退出的，返回值为0时是正常返回,2时是返回上一行，1是下一行
int Line_queue::Input()
{
	int ch;
	Char_Node *pTemp = pHead;
	
	for (int i=0; i<Pointer; i++)
	{
		pTemp = pTemp->next;
	}

	Char_Node *pTemp1;

	
	ch=getch();

	if ( ch != 13 && ch != 27 )
	{
		

		if (ch == '\b')
		{
			Pointer--;
			if ( pTemp->last!=NULL)
			{
				pTemp->last->next = pTemp->next;
				pTemp1 = pTemp->last;
				delete pTemp;
				pTemp = pTemp1;
			}
			else
			{
				//没有字符可删，回到上一行
				return 2;
			}
		}
		else//正常添加的情况
		{
			pTemp1 = new Char_Node;

			//将新节点连接
			pTemp1->ch = ch;
			pTemp1->last = pTemp;
			pTemp1->next=pTemp->next;
			//pTemp->next->last = pTemp1;
			pTemp->next = pTemp1;
			Pointer++;
			//pTemp往后挪一位
			pTemp = pTemp->next;
			return 0;
		}
		
		//this->Diplay_One_Line();//每次更改，每次输出
	}

	if (ch == 13)
	{
			//这段目的是吧\n录进去
		pTemp1 = new Char_Node;
		pTemp1->ch = ch;
		pTemp1->last = pTemp;
		pTemp1->next=pTemp->next;
		//pTemp->next->last = pTemp1;
		pTemp->next = pTemp1;
		//this->Diplay_One_Line();
		return 1;
	}
	else if (ch == 27)
	{
		return 3;
	}
	
}

int Line_queue::Length()
{
	Char_Node *pTemp = pHead;
	int count;
	for ( count = 0; pTemp!=NULL; pTemp = pTemp->next )
	{
		count++;
	}

	m_Length = count;

	return count;
}

int Line_queue::Diplay_One_Line()
{
	Char_Node *Display_Pointer = pHead->next;

	//cout << '\r' ;
	//system("cls");

/*	for (int i=0; i<m_Tabs; i++)
	{
		cout << "	";
	}
	*/ // 这一段为了控制缩进，但事实暂时无法实现自动缩近
	int count=0;

	while (Display_Pointer!=NULL)
	{
		
		cout << Display_Pointer->ch ;
		Display_Pointer = Display_Pointer->next;

		//输入光标控制
		if (count==Pointer-1)
		{
			cout << "_";
		}
		count++;
	}

	return count;
}

