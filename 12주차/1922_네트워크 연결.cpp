#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
vector<pair<int, pair<int, int>>> vec;
vector<int> parent(1002), level(1002, 0);
int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	if (level[u] > level[v]) swap(u, v);
	parent[u] = v;
	if (level[u] == level[v]) level[v]++;
}
bool isSameSet(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return 1;
	return 0;
}
void solve() {
	for (int i = 0; i < vec.size(); i++) {
		int cost = vec[i].first;
		int u = vec[i].second.first;
		int v = vec[i].second.second;
		if (!isSameSet(u, v)) {
			ans += cost;
			merge(u, v);
		}
	}

}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec.push_back({ c, {a, b} });
	}
	sort(vec.begin(), vec.end());
	solve();
	cout << ans;
}