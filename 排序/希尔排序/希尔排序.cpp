//Ï£¶ûÅÅÐò
#include <iostream>

using namespace std;

void ShellSort(int *r, int n)
{
	int i,j,d;
	for (d=n/2; d>=1; d=d/2)
	{
		for (i=d+1; i<=n; i++)
		{
			r[0] = r[i];
			for (j=i-d; j>0 && r[0] < r[j]; j=j-d)
			{
				cout << r[j] << " ";
				r[j + d] = r[j];
			}

			r[j + d] = r[0];
		}
		cout << endl;
	}
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

	ShellSort(a, n);

	for (i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}

	delete[] a;

	return 0;
}