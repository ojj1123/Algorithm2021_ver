#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[102];
int dist[102][102];
int n, m;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> board[i];
	for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	dist[0][0] = 0;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = cur.X + dx[d];
			int ny = cur.Y + dy[d];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] != '1' || dist[nx][ny] >= 0) continue;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx,ny });

		}
	}
	cout << dist[n - 1][m - 1] + 1;
}