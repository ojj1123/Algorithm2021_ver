#include <bits/stdc++.h>
using namespace std;

int arr[100002];
bool vis[100002];
bool done[100002];
int t, n, cnt;
void dfs(int v) {
	vis[v] = 1;
	int next = arr[v];
	if (!vis[next]) dfs(next);
	else {
		if (!done[next]) {
			for (int i = next; i != v; i = arr[i])
				cnt++;
			cnt++;
		}
	}
	done[v] = 1;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		cnt = 0;
		fill(vis, vis + n + 1, 0);
		fill(done, done + n + 1, 0);
		for (int i = 1; i <= n; i++) cin >> arr[i];
		for (int i = 1; i <= n; i++) {
			if (!vis[i])
				dfs(i);
		}
		cout << n - cnt << '\n';
	}
}