//÷±Ω”≤Â»Î
#include <iostream>

using namespace std;

void InsertSort(int *r, int n)
{
	int i, j;
	int flag = 0;
	for ( i=2; i<=n; i++)
	{
		flag = 0;
		r[0] = r[i];
		for (j=i-1; r[0]<r[j]; j--)
		{
			flag = 1;
			cout << r[j] << " ";
			r[j + 1] = r[j];
		}
		if (flag == 1)
		{
			cout << endl;
		}
		
		r[j + 1] = r[0];
	}
}

int main()
{
	int n;
	cin >> n;
	int *a = new int[n+1];

	int i;
	for ( i = 1; i <= n ; i++)
	{
		cin >> a[i];
	}

	InsertSort(a, n);


	for (i=1; i<=n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	delete[] a;
	return 0;
}