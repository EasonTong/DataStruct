#include <iostream>
//#include <queue>

using namespace std;

const int Maxsize = 10;

template <class T>
class MGraph
{
public:
	MGraph(T *a, int n, int e);
	~MGraph(void)
	{
		//delete[] visited;
	}
	void DFSTraverse(int v);
	void BFSTraverse(int v);
	void PrintMatrix();
	void DFST();
	void BFST();
private:
	T vertex[Maxsize];
	int arc[Maxsize][Maxsize];
	int vertexNum, arcNum;
	int visited[Maxsize];
};

template <class T>
void MGraph<T>::PrintMatrix()
{
	int i, j;
	for (i = 0; i<vertexNum; i++)
	{
		for (j = 0; j<vertexNum; j++)
		{
			cout << arc[i][j] << " ";
		}
		cout << endl;
	}
}

template<class T>
void MGraph<T>::DFST()
{
	int i = 0;
	for (i = 0; i < vertexNum; i++)
	{
		visited[i] = 0;
	}

	DFSTraverse(0);

}

template<class T>
void MGraph<T>::BFST()
{
	int i = 0;
	for (i = 0; i < vertexNum; i++)
	{
		visited[i] = 0;
	}

	BFSTraverse(0);
}

template <class T>
void MGraph<T>::BFSTraverse(int v)
{
	//queue<int> Q;
	int front = -1;
	int rear = -1;
	int Q[Maxsize + 1];
	
	
	if (visited[v] == 0)
	{
		cout << vertex[v] << " ";
		visited[v] = 1;
		Q[++rear] = v;
	}
	
	//cout << vertex[v] << " ";
	//visited[v] = 1;
	//Q[++rear] = v;

	int j;
	while (front!=rear)
	{
		v = Q[++front];
		
		for (j = 0; j<vertexNum; j++)
		{
			if (arc[v][j] == 1 && visited[j] == 0)
			{
				cout << vertex[j] << " ";
				visited[j] = 1;
				Q[++rear] = j;
			}
		}
	}
}

template <class T>
void MGraph<T>::DFSTraverse(int v)
{
	int j;
	
	if (visited[v] == 0)
	{
		cout << vertex[v] << " ";
		visited[v] = 1;
	}
	
	for (j = 0; j<vertexNum; j++)
	{
		if (arc[v][j] == 1 && visited[j] == 0)
		{
			DFSTraverse(j);
		}
	}
}

template <class T>
MGraph<T>::MGraph(T *a, int n, int e)
{
	int i, j, k;
	vertexNum = n;
	arcNum = e;
	for (i = 0; i<vertexNum; i++)
	{
		vertex[i] = a[i];
	}
	for (i = 0; i<vertexNum; i++)
	{
		for (j = 0; j<vertexNum; j++)
		{
			arc[i][j] = 0;
		}
	}

	for (k = 0; k<arcNum; k++)
	{
		cin >> i >> j;
		arc[i][j] = 1;
		arc[j][i] = 1;
	}
}



int main()
{
	int n, e, i;
	cin >> n >> e;
	char ch[100];
	for (i = 0; i<n; i++)
	{
		cin >> ch[i];
	}

	MGraph<char> A(ch, n, e);

	for (i = 0; i<n; i++)
	{
		cout << ch[i] << " ";
	}
	cout << endl;

	A.PrintMatrix();
	A.DFST();
	cout << endl;
	A.BFST();

	return 0;
}
