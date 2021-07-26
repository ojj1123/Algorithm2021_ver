#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int sz = 100003;
int n, k;
vector<pair<int, int>> dist(sz, {-1, 0}); // {걸린 시간, 전 위치}
vector<int> res;
int bfs()
{
	queue<int> q;
	dist[n] = {0, -1};
	q.push(n);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (dist[k].first != -1)
			return dist[k].first;
		for (int nx : {cur - 1, cur + 1, cur * 2})
		{
			if (nx < 0 || nx > 100000)
				continue;
			if (dist[nx].first != -1)
				continue;
			dist[nx] = {dist[cur].first + 1, cur};
			q.push(nx);
		}
	}
}
int main()
{
	cin >> n >> k;
	cout << bfs() << endl;
	int last = k;
	res.push_back(last);
	while (dist[last].second != -1)
	{
		res.push_back(dist[last].second);
		last = dist[last].second;
	}
	for (int i = res.size() - 1; i >= 0; i--)
		cout << res[i] << ' ';
	return 0;
}