#pragma once

#include <iostream>
using namespace std;
#include "LinkQueue.h";

template <class T>
struct BiNode
{
	T data;
	BiNode<T> *lchild;
	BiNode<T> *rchild;
	bool ltag;
	bool rtag;
};

//template <class T>
//struct Node
//{
//	BiNode<T> Data;
//	Node *next;
//};

template <class T>
class BiTree
{
public:
	BiTree()
	{
		root = Creat(root);
	}
	~BiTree()
	{
		Release(root);
	}
	void PreOrder()
	{
		PreOrder(root);
	}
	void InOrder()
	{
		InOrder(root);
	}
	void PostOrder()
	{
		PostOrder(root);
	}
	void LeverOrder();

private:
	BiNode<T> *root;
	BiNode<T>* Creat(BiNode<T> *bt);
	void PreOrder(BiNode<T> *bt);
	void InOrder(BiNode<T> *bt);
	void PostOrder(BiNode<T> *bt);
	void Release(BiNode<T> *bt);
	LinkQueue<BiNode<T>*> Layer;
};

template <class T>
BiNode<T>* BiTree<T>::Creat(BiNode<T> *bt)
{
	//此处可根据需要修改
	T ch;
	cin >> ch;

	if(ch == 0)
	{
		bt = NULL;
	}
	else
	{
		bt = new BiNode<T>;
		bt->data = ch;
		bt->lchild = Creat(bt->lchild);
		bt->rchild = Creat(bt->rchild);
	}

	return bt;
}

template <class T>
void BiTree<T>::PreOrder(BiNode<T> *bt)
{
	if (bt != NULL)
	{
		//以后这里的输出可能需要更改
		cout << bt->data << ' ';
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

template <class T>
void BiTree<T>::InOrder(BiNode<T> *bt)
{
	if (bt != NULL)
	{
		//以后这里的输出可能需要更改
		InOrder(bt->lchild);
		cout << bt->data << ' ';
		InOrder(bt->rchild);
	}
}

template <class T>
void BiTree<T>::PostOrder(BiNode<T> *bt)
{
	if (bt != NULL)
	{
		//以后这里的输出可能需要更改
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		cout << bt->data << ' ';
	}
}

template <class T>
void BiTree<T>::LeverOrder()
{
	//Node<T> *q;
	BiNode<T> *p;

	if (root != NULL)
	{
		Layer.EnQueue(root);
		while (!Layer.Empty())
		{
			p = (Layer.DeQueue())->Data;
			//p = q->Data;
			cout << p->data << " ";

			if (p->lchild != NULL)
			{
				Layer.EnQueue(p->lchild);
			}
			if (p->rchild != NULL)
			{
				Layer.EnQueue(p->rchild);
			}
			//delete p;
		}
	}
}

template <class T>
void BiTree<T>::Release(BiNode<T> *bt)
{
	if (bt != NULL)
	{

		Release(bt->lchild);
		Release(bt->rchild);
		delete bt;
	}
}




