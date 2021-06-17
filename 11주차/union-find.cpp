#include <bits/stdc++.h>
using namespace std;

struct DisjointSet {
	vector<int> parent;
	vector<int> rank;
	DisjointSet() : parent(21), rank(21, 0) {
		for (int i = 1; i <= 20; i++) parent[i] = i;
	};
	int find(int u) {
		if (u == parent[u]) return u;
		// 경로 압축(Path Compression)
		return parent[u] = find(parent[u]);
	}
	// union-by-rank(union-by-height)
	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		// 같은 트리(집합)이면 종료
		if (u == v) return;
		// u의 height와 v의 height비교(u가 v보다 항상 작은거로 바꿔줌)
		if (rank[u] > rank[v]) swap(u, v);
		// 항상 높이가 더 높은 트리 밑으로 높이가 낮은 트리를 넣는다.
		parent[u] = v;
		// 높이가 동일하다면 합친 후 높이를 1증가시킴
		if (rank[u] == rank[v]) rank[v]++;
	}
};
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	DisjointSet dis;
	cout<<dis.find(1); // 1
	cout << '\n';
	cout << dis.find(10); // 10
	dis.merge(1, 10);
	cout << '\n';
	cout << dis.find(1); // 10
	cout << '\n';
	cout << dis.find(10); // 10
	cout << '\n';
	dis.merge(10, 15);
	cout << dis.find(15); // 10
}