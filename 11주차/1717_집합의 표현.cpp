#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
int n, m;
int parent[MAX+2];
int level[MAX+2];

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
	for (int i = 0; i <= n; i++) parent[i] = i;
	while (m--) {
		int tmp, a, b;
		cin >> tmp >> a >> b;
		if (tmp) {
			a = find(a);
			b = find(b);
			cout << (a == b ? "YES" : "NO") << "\n";
		}
		else merge(a, b);
	}
}