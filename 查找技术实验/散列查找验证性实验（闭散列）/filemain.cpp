//散列查找验证性实验（闭散列）
#include <iostream>

using namespace std;

int HashSearch(int ht[], int m, int k, int n)
{
	int j;
	int i;
	j = k % m;
	if (ht[j] == k)
	{
		return j;
	}
	else if (ht[j] == -1)
	{
		ht[j] = k;
		return 0;
	}
	
	i = (j + 1) % m;

	while (ht[i] != -1 && i!=j)
	{
		if (ht[i]==k)
		{
			return i;
		}
		else
		{
			i = (i + 1) % n;
		}
	}

	if (i == j)
	{
		//cout << "full" << endl; 
		return -1;
	}
	else
	{
		ht[i] = k;
		return 0;
	}
}

int main()
{
	int n;
	int temp1;

	cin >> n;
	int *a = new int[n];
//	int a[11];
	int m;
	cin >> m;

	int num;
	cin >> num;
	
	//if (m >= num)
	{
		for (int j = 0; j < n; j++)
		{
			a[j] = -1;
		}

		for (int i = 0; i < num; i++)
		{
			cin >> temp1;
			HashSearch(a, m, temp1,n);
		}

		int b[3];

		cin >> b[0];
		cin >> b[1];
		cin >> b[2];

		temp1 = HashSearch(a, m, b[0], n);
		if (temp1 > 0)
		{
			cout << temp1 << endl;
		}
		else if (temp1 == 0)
		{
			cout << "none" << endl;
		}
		else if (temp1 == -1)
		{
			cout << "full" << endl;
		}

		temp1 = HashSearch(a, m, b[1], n);
		if (temp1 > 0)
		{
			cout << temp1 << endl;
		}
		else if (temp1 == 0)
		{
			cout << "none" << endl;
		}
		else if (temp1 == -1)
		{
			cout << "full" << endl;
		}

		temp1 = HashSearch(a, m, b[2], n);
		if (temp1 > 0)
		{
			cout << temp1 << endl;
		}
		else if (temp1 == 0)
		{
			cout << "none" << endl;
		}
		else if (temp1 == -1)
		{
			cout << "full" << endl;
		}
	}
	
	delete[] a;
	
	return 0;
}