#include <bits/stdc++.h>
using namespace std;
#define N 10002

int V, E;
vector<pair<int, pair<int, int>>> vec;
vector<int> parent(N), level(N, 0);
int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}
bool merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return 0; // 같은 집합이면 그냥 빠져나옴.
	if (level[u] > level[v]) swap(u, v);
	parent[u] = v;
	if (level[u] == level[v]) level[v]++;
	return 1;
}
// 크루스칼 알고리즘: 최소스패닝트리 찾기(간선을 기준으로 함.)
void solve() {
	int tot = 0;
	for (int i = 0; i < E; i++) {
		int u = vec[i].second.first;
		int v = vec[i].second.second;
		int cost = vec[i].first;
		if (merge(u, v)) tot += cost;
	}
	cout << tot;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> V >> E;
	for (int i = 1; i <= V; i++) parent[i] = i;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec.push_back({ c, {a, b} });
	}
	sort(vec.begin(), vec.end()); // 간선 기준으로 정렬!
	solve();
}