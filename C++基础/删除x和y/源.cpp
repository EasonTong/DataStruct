//É¾³ýxºÍy
#include <iostream>

using namespace std;

//int main()
//{
//	int n;
//	int x;
//	int y;
//	int a[100];
//
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//
//	cin >> x;
//	cin >> y;
//
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] == x)
//		{
//			for (int j = i; j < n - 1; j++)
//			{
//				a[j] = a[j + 1];
//			}
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] == y)
//		{
//			for (int j = i; j < n - 1; j++)
//			{
//				a[j] = a[j + 1];
//			}
//		}
//	}
//
//	for (int i = 0; i < n - 2; i++)
//	{
//		cout << a[i];
//		cout << " ";
//	}
//
//	return 0;
//}

int main()
{
	int a[100];
	int n;
	int i;
	int x;
	int y;

	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> x;
	cin >> y;
	for (i = 0; i < n; i++)
	{
		if (a[i] != x && a[i] != y)
		{
			cout << a[i] << " ";
		}
	}
	return 0;
}