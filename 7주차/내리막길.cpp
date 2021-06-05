#include <bits/stdc++.h>
using namespace std;

int n, m;
int dp[502][502];
int board[502][502];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
void bfs() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	dp[0][0] = 1;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int x = cur.first, y = cur.second;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[x][y] > board[nx][ny]) { // 내리막길이면
				if (dp[nx][ny] == 0) dp[nx][ny] = 1;
				else if (dp[nx][ny] <= dp[x][y]) dp[nx][ny]++;
				q.push({ nx,ny }); // 중복해서 들르면 안됌 시간초과 남
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> board[i][j];
	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << dp[i][j] << ' ';
		cout << '\n';
	}
	cout << dp[n - 1][m - 1];
}