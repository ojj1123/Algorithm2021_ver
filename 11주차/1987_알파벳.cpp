#include <bits/stdc++.h>
using namespace std;

string board[22];
bool check[26];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int r, c, ans;

void dfs(int x, int y, int cnt) {
	check[board[x][y] - 'A'] = 1;
	ans = max(ans, cnt);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if (!check[board[nx][ny] - 'A']) { // 아직 방문하지 않은 알파벳이면
			check[board[nx][ny] - 'A'] = 1;
			dfs(nx, ny, cnt + 1);
			check[board[nx][ny] - 'A'] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) cin >> board[i];
	check[board[0][0] - 'A'] = 1;
	dfs(0, 0, 1);
	cout << ans;
}