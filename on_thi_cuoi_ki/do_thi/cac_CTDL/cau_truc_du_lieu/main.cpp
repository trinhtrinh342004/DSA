#include <iostream>
#include <map>
#include <queue>
#include <limits>
using namespace std;

typedef priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> min_heap;

typedef pair<int, string> vertex;

const int oo = numeric_limits<int>::max();

map<string, map<string, int>> DIEM;
map<string, int> dist;

void dijkstra(string s)
{
	min_heap pq;
	pq.push(vertex(0, s));
	while (!pq.empty())
	{
		string u = pq.top().second;
		int cost_to_u = pq.top().first;
		pq.pop();
		if (dist[u] == cost_to_u)
		{
			for (auto v : DIEM[u])
			{
				if (dist[v.first] > dist[u] + v.second)
				{
					dist[v.first] = dist[u] + v.second;
					pq.push(vertex(dist[v.first], v.first));
				}
			}
		}
	}
}

void add_edge(string u, string v, int c)
{
	DIEM[u][v] = c;
	DIEM[v][u] = c;
}

int main()
{
	int e;
	cin >> e;
	for (int i = 0; i < e; i++)
	{
		string u, v;
		int c;
		cin >> u >> v >> c;
		add_edge(u, v, c);
	}

	for (auto p : DIEM)
	{
		dist[p.first] = oo;
	}

	string s;
	cin >> s;
	dijkstra(s);

	for (auto p : dist)
	{
		cout << p.first << " " << p.second << endl;
	}

	return 0;
}
