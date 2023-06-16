#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;



int n, m, st, en;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];
int color[1001];
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

//Kiem tra chu trinh tren do thi co huong su dung dfs
bool DFS(int u)
{
	color[u] = 1; //mau xam
	for (int v : adj[u])
	{
		if (color[v] == 0)
		{
			if (DFS(v))
				return true;
		}
		else if (color[v] == 1)
			return true;
	}
	color[u] = 2;// mau den
}

// Kiem tra chu trinh tren do thi vo huong su dung BFS
bool BFS(int u)
{
	visited[u] = true;
	queue<int> q;
	q.push(u);
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int x : adj[v])
		{
			if (!visited[x])
			{
				q.push(x);
				visited[x] = true;
				parent[x] = v;
			}
			else if (x != parent[v])
			{
				st = v;
				en = x;
				return true;
			}
		}
	}
	return false;
}


int main()
{
#ifdef  ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif //  ONLINE_JUDGE
	inp();
	cout << "Kiem tra do thi vo huong co chu trinh khong?\n";
	for (int i = 0; i <= n; i++)
	{
		if (!visited[i])
		{
			if (BFS(i))
			{
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";

	cout << "Kiem tra do thi co huong co chu trinh khong?\n";
	for (int i = 0; i <= n; i++)
	{
		if (color[i] == 0)
		{
			if (DFS(i))
			{
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}