#include <bits/stdc++.h>
using namespace std;

int n, m;
int route[1002];
int parent[1002];
int level[1002];

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
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		level[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int tmp;  cin >> tmp;
			if (j > i && tmp) merge(i, j);
		}
	}
	for (int i = 0; i < m; i++) cin >> route[i];
	bool flag = true;
	for (int i = 0; i < m-1; i++) {
		int u = find(route[i]);
		int v = find(route[i+1]);
		if (u != v) { // 다른 집합에 있다면 같은 경로에 있지 않다는 뜻
			flag = false;
			break;
		}
	}
	cout << (flag ? "YES" : "NO");
}