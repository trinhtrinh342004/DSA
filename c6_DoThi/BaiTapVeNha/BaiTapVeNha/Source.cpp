#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];

void inp()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}

void dfs(int u)
{
	cout << u << " ";
	// Danh dau la u da duoc chon
	visited[u] = true;
	for (int v : adj[u])
	{
		//Neu dinh v chua duoc tham
		if (!visited[v])
		{
			dfs(v);
		}
	}
}

int main()
{
	inp();
	dfs(1);
}