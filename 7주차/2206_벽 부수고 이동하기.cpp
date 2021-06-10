#include <bits/stdc++.h>
using namespace std;

string board[1002];
int vis[1002][1002][2];
int n, m;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) fill(vis[i][j], vis[i][j] + 2, -1);
	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, 0 });
	vis[0][0][0] = 1;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int cx = get<0>(cur);
		int cy = get<1>(cur);
		int cwall = get<2>(cur);
		if (cx == n - 1 && cy == m - 1) {
			cout << vis[cx][cy][cwall];
			return 0;
		}
		for (int d = 0; d < 4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == '0' && vis[nx][ny][cwall] == -1) {
				vis[nx][ny][cwall] = vis[cx][cy][cwall] + 1;
				q.push({ nx,ny,cwall });
			}
			if (board[nx][ny] == '1') {
				if (!cwall && vis[nx][ny][cwall + 1] == -1) {
					vis[nx][ny][cwall + 1] = vis[cx][cy][cwall] + 1;
					q.push({ nx,ny,cwall + 1 });
				}

			}
		}
	}
	cout << -1;
}