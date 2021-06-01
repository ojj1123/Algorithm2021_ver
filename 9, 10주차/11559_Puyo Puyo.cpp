#include <bits/stdc++.h>
using namespace std;

string board[13];
bool vis[13][7];
vector<pair<int, int>> point, emptyVec;
int ans;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void remove() {
	for (int i = 0; i < 6; i++) {
		for (int j = 10; j >= 0; j--) {
			for (int k = 11; k > j; k--) {
				if (board[j][i] != '.' && board[k][i] == '.') {
					board[k][i] = board[j][i];
					board[j][i] = '.';
					break;
				}
			}
		}
	}
}

void dfs(int x, int y, char ch) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
		if (!vis[nx][ny] && board[nx][ny] == ch) {
			point.push_back({ nx, ny });
			vis[nx][ny] = 1;
			dfs(nx, ny, ch);
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	for (int i = 0; i < 12; i++) cin >> board[i];
	while (1) {
		bool flag = 1;
		for (int i = 0; i < 12; i++) fill(vis[i], vis[i] + 6, false);
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (board[i][j] != '.' && !vis[i][j]) {
					point = emptyVec;
					dfs(i, j, board[i][j]);
					if (point.size() >= 4) { // 터트리는 곳이 4이상이면
						flag = 0;
						for (auto p : point)
							board[p.first][p.second] = '.';
					}

				}
			}
		}
		if (flag) break; // 4미만일 때,
		else ans++;
		remove();
	}
	cout << ans;
}