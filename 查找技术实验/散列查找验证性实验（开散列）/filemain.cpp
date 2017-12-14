//散列查找验证性实验（开散列）
#include <iostream>

using namespace std;


struct Node
{
	int  data;
	Node *next;
};


Node *HashSearch1(Node **ht, int m, int k)
{
	int j;
	int count = 1;
	j = k % m;
	Node *p = ht[j];
	while (p!=NULL && p->data!=k)
	{
		p = p->next;
		count++;
	}
	if (p!=NULL && p->data == k)
	{
		cout << j << " " << count << endl;
		return p;
	}
	else
	{
		Node *q = new Node;
		q->data = k;
		q->next = ht[j];
		ht[j] = q;
		return NULL;
	}
}

int main()
{
	Node *p;
	int n;
	cin >> n;
	Node **a = new Node*[n];

	int i;
	for (i=0; i<n; i++)
	{
		a[i] = NULL;
	}

	int m;
	cin >> m;
	int num;
	cin >> num;

	int temp1;
	
	for (i=0; i<num; i++)
	{
		cin >> temp1;
		HashSearch1(a, m, temp1);
	}

	int b[3];

	for (i=0; i<3; i++)
	{
		cin >> b[i];
	}

	for (i=0; i<3; i++)
	{
		p = HashSearch1(a, m, b[i]);
		if (p==NULL)
		{
			cout << "none" << endl;
		}
	}

	return 0;
}