#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define X first
#define Y second
int board[102][102];
int graph[102][102];
int dist[102][102];
int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	FAST;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> board[i][j];
	queue<pair<int, int>> Q;
	int num = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!graph[i][j] && board[i][j]) {
				Q.push({ i,j });
				graph[i][j] = num;
				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (board[nx][ny] != 1 || graph[nx][ny] >= 1) continue;
						graph[nx][ny] = num;
						Q.push({ nx,ny });
					}
				}
				num++;
			}
		}
	}
	int ans = 1001;
	for (int is = 1; is < num; is++) {
		queue<pair<int, int>> Q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = -1;
				if (graph[i][j] == is) {
					Q.push({ i,j });
					dist[i][j] = 0;
				}
			}
		}
		while (!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					if (dist[nx][ny] == -1) {
						dist[nx][ny] = dist[cur.X][cur.Y] + 1;
						Q.push({ nx, ny });
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (graph[i][j] != is && graph[i][j] != 0) {
					if (dist[i][j] - 1 < ans) ans = dist[i][j] - 1;
				}
			}
		}
	}
	cout << ans;
	return 0;
}