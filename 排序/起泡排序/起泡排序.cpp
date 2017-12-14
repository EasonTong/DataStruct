//ÆðÅÝÅÅÐò
#include <iostream>

using namespace std;

void BubbleSort(int *r, int n)
{
	int exchange;
	int Bound;
	int i;
	exchange = n;
	int flag;

	while (exchange != 0)
	{
		Bound = exchange;
		exchange = 0;
		flag = 0;
		for (i=0; i<Bound; i++)
		{
			if (r[i] > r[i+1])
			{
				cout << r[i + 1] << " " ;
				r[i] = r[i] ^ r[i + 1];
				r[i+1] = r[i] ^ r[i + 1];
				r[i] = r[i] ^ r[i + 1];
				exchange = i;
				flag = 1;
			}
		}

		if (flag==1)
		{
			cout << endl;
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

	BubbleSort(a, n);

	for (i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}

	return 0;
}