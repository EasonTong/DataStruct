//顺序查找验证程序
#include <iostream>

using namespace std;

int SeqSearch(int *r, int n, int k)
{
	int i;

	r[0] = k;
	i = n;
	while (r[i] != k)
	{
		cout << r[i] << " ";
		i--;
	}
	cout << endl;
	return i;
}

int main()
{
	int n;
	cin >> n;
	int i;
	int *a = new int[n + 1];

	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	int BeSearched;
	int Ans;

	for (i = 0; i < 3; i++)
	{
		cin >> BeSearched;
		Ans = SeqSearch(a, n, BeSearched);
		cout << Ans << endl;
	}

	delete[] a;
	return 0;
}