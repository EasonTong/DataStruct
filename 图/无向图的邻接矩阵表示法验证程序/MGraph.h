#pragma once
#include <iostream>
#include <queue>

using namespace std;

const int Maxsize = 10;

template <class T>
class MGraph
{
public:
	MGraph(T *a, int n, int e);
	~MGraph(void)
	{
		delete [] visited;
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
	bool *visited = new bool[Maxsize];
};

template <class T>
void MGraph<T>::PrintMatrix()
{
	int i,j;
	for (i=0; i<vertexNum; i++)
	{
		for (j=0; j<vertexNum; j++)
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
	queue<int> Q;
	cout << vertex[v] << " ";
	visited[v] = 1;
	Q.push(v);
	int j;
	while (!Q.empty())
	{
		v = Q.front();
		Q.pop();
		for (j=0; j<vertexNum; j++)
		{
			if (arc[v][j]==1 && visited[j]==0)
			{
				cout << vertex[j] << " ";
				visited[j] = 1;
				Q.push(j);
			}
		}
	}
}

template <class T>
void MGraph<T>::DFSTraverse(int v)
{
	int j;

	cout << vertex[v] << " ";
	visited[v] = 1;
	for (j=0; j<vertexNum; j++)
	{
		if (arc[v][j]==1 && visited[j]==0)
		{
			DFSTraverse(j);
		}
	}
}

template <class T>
MGraph<T>::MGraph(T *a, int n, int e)
{
	int i,j,k;
	vertexNum = n;
	arcNum = e;
	for (i=0; i<vertexNum; i++)
	{
		vertex[i] = a[i];
	}
	for (i=0; i<vertexNum; i++)
	{
		for (j=0; j<vertexNum; j++)
		{
			arc[i][j] = 0;
		}
	}

	for (k=0; k<arcNum; k++)
	{
		cin >> i >> j; 
		arc[i][j] = 1;
		arc[j][i] = 1;
	}
}

