//πÈ≤¢≈≈–Ú
#include <iostream>

using namespace std;

void Merge(int *r, int *r1, int s, int m, int t)
{
	int i = s;
	int j = m + 1;
	int k = s;

	while (i<=m && j<=t)
	{
		if (r[i] <= r[j])
		{
			r1[k++] = r[i++];
		}
		else
		{
			r1[k++] = r[j++];
		}
	}

	if (i <= m)
	{
		while (i <= m)
		{
			r1[k++] = r[i++];
		}
	}
	else
	{
		while (j <= t)
		{
			r1[k++] = r[j++];
		}
	}
}

void MergePass(int *r, int *r1, int n, int h)
{
	int i = 1;

	while (i <= n - 2 * h + 1)
	{
		Merge(r, r1, i, i + h - 1, i + 2 * h - 1);
		i += 2 * h;
	}

	if (i < n-h+1)
	{
		Merge(r, r1, i, i + h - 1, n);
	}
	else
	{
		for (int k=i; k<=n; k++)
		{
			r1[k] = r[k];
		}
	}
}

void MergeSort(int *r, int *r1, int n)
{
	int h = 1;
	while (h < n)
	{
		MergePass(r, r1, n, h);
		h = 2 * h;
		MergePass(r1, r, n, h);
		h = 2 * h;
	}
}

int main()
{
	int n;
	cin >> n;
	int *a = new int[n / 2 + 1];
	int *b = new int[n / 2 + 1];

	int i;
	for (i = 1; i <= n / 2 ; i++)
	{
		cin >> a[i];
	}

	for (i = 1; i <= n / 2 ; i++)
	{
		cin >> b[i];
	}

	MergeSort(a, b, n);

	for (i = 1; i <= n/2 ; i++)
	{
		cout << a[i] << " ";
	}

	for (i = 1; i <= n / 2; i++)
	{
		cout << b[i] << " ";
	}

	delete[] a;

	return 0;
}