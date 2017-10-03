//找到数组中的最大值，输出最大的的位置和最大值
#include <iostream>

using namespace std;



int main()
{
	int a[100];
	int n;
	cin >> n;
	int i,Max,Poz;

	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	Max = a[0];

	for (i = 0; i < n; i++)
	{
		if (a[i] >= Max)
		{
			Max = a[i];
			Poz = i;
		}
	}
	
	cout << Poz << " " << Max;

	return 0;
}