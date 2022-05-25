#include <bits/stdc++.h>
using namespace std;
int M = 10;
int Root[10];
int find_fn(int x)
{
	while (Root[x] != x)
		x = Root[x];
	return x;
}

void union_fn(int x, int y)
{
	int u = find_fn(x);
	int v = find_fn(y);
	Root[u] = v;
}
void Krus_kal(int K_cost[][10])
{
	int m_cost = 0; 
	for (int x = 0; x < 10; x++)
		Root[x] = x;
	int K_edge = 0;
	while (K_edge < 10 - 1) 
	{
		int low = INT_MAX, u = -1, v = -1;
		for (int x = 0; x < 10; x++) 
		{
			for (int y = 0; y < 10; y++) 
			{
				if (find_fn(x) != find_fn(y) && K_cost[x][y] < low) 
				{
					low = K_cost[x][y];
					u = x;
					v = y;
				}
			}
		}

		union_fn(u, v);
		printf("Edge of Graph %d:(%d, %d) Cost of Graph:%d \n",K_edge++, u, v, low);
		m_cost += low;
	}
	printf("\n The Minimum cost of Graph = %d \n", m_cost);
}

int main()
{
int  K_cost[][10] = {
		{ INT_MAX, 1, INT_MAX, 2, INT_MAX },
		{ 2, INT_MAX, 3 , 2, 2},
		{ INT_MAX, 3, INT_MAX,4, INT_MAX, 4,5 },
		{ INT_MAX, 2 ,INT_MAX, INT_MAX, 3 },
		{ INT_MAX, 1 ,INT_MAX, INT_MAX, 5 }
	};
	Krus_kal(K_cost);

	return 0;}

