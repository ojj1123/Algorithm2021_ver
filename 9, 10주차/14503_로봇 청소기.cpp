#include <bits/stdc++.h>
using namespace std;

int board[52][52]; // 벽 : 1, 빈공간 : 0 
int n, m, ans;
int r, c, d;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0 ,1, 0, -1 };
int backx[] = { 1, 0, -1, 0 };
int backy[] = { 0, -1, 0, 1 };
int search_dir;

void solve(int x, int y, int d) {
	if (board[x][y] == 0) {
		ans++;
		board[x][y] = 2;
	}
	for (int i = (d + 3); i >= d; i--) { // 왼쪽부터 차례대로
		int search_dir = i % 4;
		int nx = x + dx[search_dir];
		int ny = y + dy[search_dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (board[nx][ny] == 0) { // 청소 가능하면
			solve(nx, ny, search_dir); // 그쪽으로 이동하고 방향도 회전
			return;
		}
	} // 네 방향 모두 순회
	// 네 방향 다 탐색했는데 모두 청소 불가
	if (board[x + backx[d]][y + backy[d]] == 1) return; //벽이면
	else solve(x + backx[d], y + backy[d], d);
}
int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> r >> c >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)	cin >> board[i][j];
	solve(r, c, d);
	cout << ans;
}