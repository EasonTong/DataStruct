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

	//�ҵ����ʵı༭λ��
	for (int i=0; i<Pointer_Line; i++)
	{
		pTemp_Line=pTemp_Line->next;
	}

	//��ʼ�༭
	while (flag!=3)
	{
		flag = pTemp_Line->Input();
		

		if (flag == 1)
		{//����ע�⻹��Ҫ������
			pTemp_Line1 = new Line_queue;
			pTemp_Line1->last = pTemp_Line;
			pTemp_Line1->next = pTemp_Line->next;
			pTemp_Line->next = pTemp_Line1;

			//ָ���л�����һ��
			pTemp_Line = pTemp_Line1;
			Display_End++;
		}
		if (flag == 2)
		{
			cout << "sad";
			if(pTemp_Line != pHead)
			{	//����������
				pTemp_Line1 = pTemp_Line;
				pTemp_Line = pTemp_Line->last;//�˴�����ЩС���⣬֮����Ҫ�޸ģ����ǻ�û����ȷ����������ʲô
				//��ֹ�ʼ���������ڴ汨��
				pTemp_Line->next = pTemp_Line1->next;

				if (pTemp_Line1->next!=NULL)
				{
					pTemp_Line1->next->last = pTemp_Line1;
				}
//				delete pTemp_Line1;// �����������ڴ汨��
				
				Display_End--;//û�취���������������취
			}	
		}
		this->Display_Page(0);//�պ��޸�,display line pozition
	}
	
}

void Page_queue::Display_Page(int Display_Start)
{
	Line_queue *pTemp_Display;
	pTemp_Display = pHead;

	int counter=0;//���������Ϊ20��
	int count_Line=0;//����������
	int count_all_char=0;//�������ַ���

	system("cls");
	//�ҵ����ʵ���ʾ��ʼλ��
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
