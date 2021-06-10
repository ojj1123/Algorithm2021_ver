// 1926_그림 문제랑 유사함.
#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int board[1002][1002];
bool vis[1002];
int n, m;//정점의 개수, 간선의 개수

int main() {
	FAST;
	int cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		board[x][y] = board[y][x] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		queue<int> Q;
		Q.push(i);
		vis[i] = 1;
		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			for (int j = 1; j <= n; j++) {
				if (board[cur][j] != 1 || vis[j]) continue;
				vis[j] = 1;
				Q.push(j);
			}
		}
		cnt++;
	}
	cout << cnt;

	return 0;
}