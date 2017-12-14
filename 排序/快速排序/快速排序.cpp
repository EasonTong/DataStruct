//¿ìËÙÅÅĞò
#include <iostream>

using namespace std;

struct Node
{
	int data;
	int flag;
};

Node Partition(int *r, int first, int end)
{
	int i = first;
	int j = end;
	int flag = 0;
	while (i < j)
	{
		while (i<j && r[i]<=r[j])
		{
			j--;
		}

		if (i < j)
		{
			cout << r[j] << " ";
			r[i] = r[i] ^ r[j];
			r[j] = r[i] ^ r[j];
			r[i] = r[i] ^ r[j];
			i++;
			flag = 1;
		}

		while (i<j && r[i]<=r[j])
		{
			i++;
		}

		if (i < j)
		{
			cout << r[i] << " ";
			r[i] = r[i] ^ r[j];
			r[j] = r[i] ^ r[j];
			r[i] = r[i] ^ r[j];
			j--;
			flag = 1;
		}

//		cout << endl;
	}

	Node No;
	No.data = i;
	No.flag = flag;
	return No;
}

void QuickSort(int *r, int first, int end)
{
	int pivot;
	Node no;

	if (first < end)
	{
		no = Partition(r, first, end);
		pivot = no.data;
		if (no.flag == 1)
		{
			cout << endl;
		}


		QuickSort(r, first, pivot - 1);

		QuickSort(r, pivot + 1, end);
		
	}

	
//	cout << endl;

}

int main()
{
	int n;
	cin >> n;
	int *a = new int[n + 1];

	int i;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	QuickSort(a, 1, n);

	for (i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}

	delete[] a;

	return 0;
}