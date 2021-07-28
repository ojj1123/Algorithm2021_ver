#include <bits/stdc++.h>
using namespace std;

int board[502][502];
int dp[502][502];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int n, m;
int dfs(int x, int y) {
	if (x == n - 1 && y == m - 1) return 1;
	else if (dp[x][y] == -1) {
		dp[x][y] = 0;
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[x][y] > board[nx][ny]) dp[x][y] += dfs(nx, ny);
		}
	}
	return dp[x][y];
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) fill(dp[i], dp[i] + m + 1, -1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> board[i][j];
	cout << dfs(0, 0);
}