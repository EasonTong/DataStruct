#include <iostream>

using namespace std;

int main()
{
	double a = 0.1;
	/*double b = 2;
	double c = 3;
	double d = 6;
	double e = 9;*/
	for (int i = 0; i < 100000; i++)
	{
		a = a + a;
		cout << a << endl;
	}

	cout << a;

	//if ((a/c + b/d) == 2*(c/e))
	//{
	//	//cout << "1";
	//	cout << a/c << endl;
	//	cout << b/d << endl;
	//	cout << c/e << endl;

	//}
	//else
	//{
	//	cout << "0";
	//}

	return 0;
}