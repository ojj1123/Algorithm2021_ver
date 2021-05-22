#include <bits/stdc++.h>
using namespace std;

int board[102][102][102];
int dist[102][102][102];
int n, m, h;
int dx[] = { 1,0,-1,0, 0,0 };
int dy[] = { 0,1,0,-1, 0,0 };
int dz[] = { 0,0,0,0,1,-1 };
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> m >> n >> h;//가로, 세로, 높이
	bool flag = true;
	queue < tuple <int, int, int >> t;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int temp; cin >> temp;
				board[k][i][j] = temp;
				if (temp == 1)
					t.push({ k,i,j });
				if (temp == 0) {//안 익은 토마토가 있음
					dist[k][i][j] = -1;
					flag = false;
				}
			}
		}
	}
	if (flag) {
		cout << 0;
		return 0;
	}
	while (!t.empty()) {
		auto cur = t.front(); t.pop();
		int curX = get<1>(cur);
		int curY = get<2>(cur);
		int curZ = get<0>(cur);
		for (int dir = 0; dir < 6; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			int nz = curZ + dz[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (dist[nz][nx][ny] >= 0) continue;
			dist[nz][nx][ny] = dist[curZ][curX][curY] + 1;
			t.push({ nz,nx,ny });
		}
	}
	int ans = 0;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (dist[k][i][j] == -1) {
					cout << -1;
					return 0;
				 }
				ans = max(ans, dist[k][i][j]);
			}
		}
	}
	cout << ans;
}