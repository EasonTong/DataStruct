#include <conio.h>
#include "Line_queue.h"


Line_queue::Line_queue(void)
{
	pHead = new Char_Node;
	pHead->next = NULL;//�ַ�ͷ����ʼ��
	pHead->last = NULL;
//	m_Tabs = 0;
	Pointer=0;
}


Line_queue::~Line_queue(void)
{
	//��������
	Char_Node *p_next = pHead;
	while(p_next!=NULL)
	{
		p_next = pHead;
		delete p_next;
		pHead = pHead->next;
	}
}


//����ֵΪ3ʱ���ֶ��˳��ģ�����ֵΪ0ʱ����������,2ʱ�Ƿ�����һ�У�1����һ��
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
				//û���ַ���ɾ���ص���һ��
				return 2;
			}
		}
		else//������ӵ����
		{
			pTemp1 = new Char_Node;

			//���½ڵ�����
			pTemp1->ch = ch;
			pTemp1->last = pTemp;
			pTemp1->next=pTemp->next;
			//pTemp->next->last = pTemp1;
			pTemp->next = pTemp1;
			Pointer++;
			//pTemp����Ųһλ
			pTemp = pTemp->next;
			return 0;
		}
		
		//this->Diplay_One_Line();//ÿ�θ��ģ�ÿ�����
	}

	if (ch == 13)
	{
			//���Ŀ���ǰ�\n¼��ȥ
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
	*/ // ��һ��Ϊ�˿�������������ʵ��ʱ�޷�ʵ���Զ�����
	int count=0;

	while (Display_Pointer!=NULL)
	{
		
		cout << Display_Pointer->ch ;
		Display_Pointer = Display_Pointer->next;

		//���������
		if (count==Pointer-1)
		{
			cout << "_";
		}
		count++;
	}

	return count;
}

