#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define X first
#define Y second

int board[52][52];
bool vis[52][52];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main() {
	FAST;
	int t; cin >> t;
	while (t--) {
		int n, m, k, cnt = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < 50; i++) {
			fill(board[i], board[i] + 50, 0);
			fill(vis[i], vis[i] + 50, 0);
		}
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;// x-->m: 가로, y-->n: 세로
			board[y][x] = 1;
		}
		queue < pair<int, int> > Q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] != 1 || vis[i][j]) continue;
				Q.push({ i,j });
				vis[i][j] = 1;
				cnt++;
				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (board[nx][ny] != 1 || vis[nx][ny]) continue;
						vis[nx][ny] = 1;
						Q.push({ nx,ny });
					}
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}