#include <bits/stdc++.h>
using namespace std;
#define MAX 10002
vector<pair<int, int>> vec[MAX];
bool vis[MAX];
int n, ans;
int farnode;

void dfs(int v, int dist) {
	vis[v] = 1;
	if (ans < dist) {
		ans = dist;
		farnode = v; // 가장 멀리 있는 노드로 설정함
	}
	for (int i = 0; i < vec[v].size(); i++) {
		int next = vec[v][i].first; // 가려는 곳
		int weight = vec[v][i].second; // 가려는 곳으로 갈때의 거리
		if (vis[next]) continue;
		vis[next] = 1;
		dfs(next, dist+weight);
		vis[next] = 0;
	}

}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		vec[u].push_back({ v, w });
		vec[v].push_back({ u, w }); // 인접리스트
	}
	vis[1] = 0;
	dfs(1, 0);
	fill(vis, vis + n + 1, 0);
	dfs(farnode, 0);
	cout << ans;
}