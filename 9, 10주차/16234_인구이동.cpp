#include <bits/stdc++.h>
using namespace std;

int board[52][52];
bool vis[52][52];
vector<pair<int, int>> vec, emptyVec;
int n, l, r, ans;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void move() {
	int tmp = 0;
	for (auto v : vec) tmp += board[v.first][v.second];
	tmp /= vec.size();
	for (auto v : vec) board[v.first][v.second] = tmp;
}
void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		int diff = abs(board[x][y] - board[nx][ny]);
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (!vis[nx][ny] && l <= diff && diff <= r) {
			vec.push_back({ nx, ny });
			vis[nx][ny] = 1;
			dfs(nx, ny);
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> board[i][j];
	while (1) {
		bool flag = 1;
		for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!vis[i][j]) {
					vec = emptyVec;
					vec.push_back({ i, j });
					vis[i][j] = 1;
					dfs(i, j);
					if (vec.size() > 1) {
						move();
						flag = 0;
					}
				}
			}
		}
		if (flag) break;
		else ans++;
	}
	cout << ans;
}