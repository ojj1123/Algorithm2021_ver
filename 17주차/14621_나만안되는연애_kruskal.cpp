#include <bits/stdc++.h>
using namespace std;
int n, m;
bool gen[1001];
int parent[1001];
int level[1001];
vector<pair<int, pair<int, int>>> graph;
void init()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		char c;
		cin >> c;
		if (c == 'M')
			gen[i] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph.push_back({c, {a, b}});
	}
	sort(graph.begin(), graph.end());
	for (int i = 1; i <= n; i++)
		parent[i] = i;
}
int find(int u)
{
	if (u == parent[u])
		return u;
	return parent[u] = find(parent[u]);
}
void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u == v)
		return;
	if (level[u] > level[v])
		swap(u, v);
	parent[u] = v;
	if (level[u] == level[v])
		level[v]++;
}
bool isSameSet(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u == v)
		return 1;
	return 0;
}
int kruskal()
{
	int cnt = 0, ret = 0;
	for (int i = 0; i < graph.size(); i++)
	{
		if (cnt == n - 1)
			break;
		int d = graph[i].first;
		int u = graph[i].second.first;
		int v = graph[i].second.second;
		if (gen[u] == gen[v]) // 인접한 것이 성별이 같으면
			continue;
		if (!isSameSet(u, v))
		{
			merge(u, v);
			ret += d;
			cnt++;
		}
	}
	if (cnt != n - 1)
		return -1;
	return ret;
}

int main()
{
	init();
	cout << kruskal();
	return 0;
}