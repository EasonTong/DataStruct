//—°‘Ò≈≈–Ú
#include <iostream>

using namespace std;

void SeclectSort(int *r, int n)
{
	int i,j;
	int flag;
	int temp;
	int index;
	for (i=1; i<n; i++)
	{
		flag = 0;
		index = i;
		for (j= i+1; j <= n; j++)
		{
			if (r[j] < r[index])
			{
				cout << r[j] << " " ;
				index = j;
				flag = 1;
			}
		}

		if (flag==1)
		{
			cout << endl;
		}
		
		if (index != i)
		{
			//cout << r[index] << " " << r[i] << " " << r[j] << endl;
			temp = r[index];
			r[index] = r[i];
			r[i] = temp;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int *a = new int[n + 1];

	int i;
	for (i=1; i<=n; i++)
	{
		cin >> a[i];
	}

	SeclectSort(a, n);

	for (i=1; i<=n; i++)
	{
		cout << a[i] << " ";
	}

	delete[] a;

	return 0;
}