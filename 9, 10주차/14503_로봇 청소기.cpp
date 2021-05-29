#include <bits/stdc++.h>
using namespace std;

int board[52][52]; // �� : 1, ����� : 0 
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
	for (int i = (d + 3); i >= d; i--) { // ���ʺ��� ���ʴ��
		int search_dir = i % 4;
		int nx = x + dx[search_dir];
		int ny = y + dy[search_dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (board[nx][ny] == 0) { // û�� �����ϸ�
			solve(nx, ny, search_dir); // �������� �̵��ϰ� ���⵵ ȸ��
			return;
		}
	} // �� ���� ��� ��ȸ
	// �� ���� �� Ž���ߴµ� ��� û�� �Ұ�
	if (board[x + backx[d]][y + backy[d]] == 1) return; //���̸�
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