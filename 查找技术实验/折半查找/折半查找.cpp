//折半查找
#include <iostream>

using namespace std;

int BinSearch(int *r, int n, int k)
{
	int low = 1;
	int high = n;
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;
		
		//按要求输出
		cout << low << " " << mid << " " << high << " " << r[mid] << endl;
		
		if (k<r[mid])
		{
			high = mid - 1;
		}
		else if (k > r[mid])
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}

	return 0;
}

int main()
{
	int n;
	cin >> n;
	int Searched;
	int *a = new int[n + 1];

	for (int  i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < 3; i++)
	{
		cin >> Searched;
		cout << BinSearch(a, n, Searched) << endl;
	}

	delete[] a;

	return 0;
}