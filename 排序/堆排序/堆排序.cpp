// 数据结构.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>

using namespace std;

void Shift(int r[], int k, int m, int *flag)
{
	int i, j, p = 0;
	i = k;
	j = 2 * i;
	*flag = 0;
	while (j <= m)
	{
		if (j < m && r[j] < r[j + 1]) j++;
		if (r[i] > r[j]) break;
		else
		{
			cout << r[j] << " ";
			r[0] = r[i];
			r[i] = r[j];
			r[j] = r[0];
			i = j;
			j = 2 * i;
			*flag = 1;
		}

	}
}

void HeapSort(int r[], int n)
{
	int i;
	int flag;
	for (i = n / 2; i >= 1; i--)
	{
		Shift(r, i, n, &flag);
		if (flag == 1)
			cout << endl;
	}

	for (i = 1; i <= n; i++)
		cout << r[i] << " ";
	cout << endl;
	for (i = 1; i < n; i++)
	{
		r[0] = r[1];
		r[1] = r[n - i + 1];
		r[n - i + 1] = r[0];
		Shift(r, 1, n - i, &flag);
		if (flag == 1)
			cout << endl;
	}

	for (i = 1; i <= n; i++)
		cout << r[i] << " ";
	cout << endl;
}

int main()
{
	int a[20];
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	HeapSort(a, n);
	return 0;
}
