#include <iostream>

using namespace std;

template <class T>
struct MyStruct
{
	T Data;
};

template <class T>
T function(char x)
{
	MyStruct<T> B;
	B.Data
}

int main()
{
	MyStruct<char> A;

	return 0;
}