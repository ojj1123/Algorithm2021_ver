#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[1002];
int dist1[1002][1002];
int dist2[1002][1002];
int r, c;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> r >> c;
	queue<pair<int, int>> q, q1;
	for (int i = 0; i < r; i++) {
		fill(dist1[i], dist1[i] + c, -1);
		fill(dist2[i], dist2[i] + c, -1);
	}
	for (int i = 0; i < r; i++) cin >> board[i];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'F') {
				dist1[i][j] = 0;
				q.push({ i,j });
			}
			if (board[i][j] == 'J') {
				dist2[i][j] = 0;
				q1.push({ i, j });
			}
		}
	}
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = cur.X + dx[d];
			int ny = cur.Y + dy[d];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (board[nx][ny] == '#' || dist1[nx][ny] >= 0) continue;
			dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
			q.push({ nx,ny });
		}
	}
	while (!q1.empty()) {
		auto cur = q1.front(); q1.pop();
		for (int d = 0; d < 4; d++) {
			int nx = cur.X + dx[d];
			int ny = cur.Y + dy[d];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
				cout << dist2[cur.X][cur.Y] + 1;
				return 0;
			}
			if (board[nx][ny] == '#' || dist2[nx][ny] >= 0) continue;
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue;
			dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
			q1.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE";
}