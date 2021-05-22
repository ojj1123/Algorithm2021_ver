#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define X first
#define Y second

bool vis[302][302];
int n, m;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int main() {
	FAST;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m)), temp;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> board[i][j];
	temp = board;
	int cnt = 0;
	queue<pair<int, int>> q2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] != 0 && vis[i][j] == 0) {
				q2.push({ i,j });
				vis[i][j] = 1;
				cnt++;
				while (!q2.empty()) {
					auto cur = q2.front(); q2.pop();
					for (int d = 0; d < 4; d++) {
						int nx = cur.X + dx[d];
						int ny = cur.Y + dy[d];
						if (board[nx][ny] == 0) {
							temp[cur.X][cur.Y]--;
							if (temp[cur.X][cur.Y] < 0) temp[cur.X][cur.Y] = 0;
							continue;
						}
						if (board[nx][ny] > 0 && vis[nx][ny] == 0) {
							vis[nx][ny] = 1;
							q2.push({ nx,ny });
						}
					}
				}
			}
		}
	}
	board = temp;
	int year = 0;
	while (1) {
		if (cnt >= 2) break;
		else if (cnt == 0) {
			year = 0;
			break;
		}
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++) fill(vis[i], vis[i] + m, 0);
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] != 0 && vis[i][j]==0) {
					q.push({ i,j });
					vis[i][j] = 1;
					cnt++;
					while (!q.empty()) {
						auto cur = q.front(); q.pop();
						for (int d = 0; d < 4; d++) {
							int nx = cur.X + dx[d];
							int ny = cur.Y + dy[d];
							if (board[nx][ny] == 0) {
								temp[cur.X][cur.Y]--;
								if (temp[cur.X][cur.Y] < 0) temp[cur.X][cur.Y] = 0;
								continue;
							}
							if (board[nx][ny] > 0 && vis[nx][ny]==0) {
								vis[nx][ny] = 1;
								q.push({ nx,ny });
							}
						}
					}
				}
			}
		}

		board = temp;
		year++;
	}
	cout << year;
	return 0;
}