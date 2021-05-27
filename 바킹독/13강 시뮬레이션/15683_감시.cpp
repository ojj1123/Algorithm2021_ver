#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> board(8, vector<int>(8, 0)); // ������ �κ��� -1�� �ٲ���
vector<tuple<int, int, int>> vec;
int cctv_cnt;
int n, m, ans = 100;

void move(int dir, int x, int y) {
	switch (dir) {
	case 0: // ��
		for (int i = x + 1; i < n; i++) {
			if (board[i][y] == 6) break;
			if (board[i][y] == 0)board[i][y] = -1;
		}
		break;
	case 1: // ��
		for (int i = y + 1; i < m; i++) {
			if (board[x][i] == 6) break;
			if (board[x][i] == 0) board[x][i] = -1;
		}
		break;
	case 2: // ��
		for (int i = x - 1; i >= 0; i--) {
			if (board[i][y] == 6) break;
			if (board[i][y] == 0) board[i][y] = -1;
		}
		break;
	case 3: // ��
		for (int i = y - 1; i >= 0; i--) {
			if (board[x][i] == 6) break;
			if (board[x][i] == 0) board[x][i] = -1;
		}
		break;
	}
}
void dfs(int k) {
	//��ü cctv�� �� ����, �簢���� �ּڰ� ��ȯ
	if (k == cctv_cnt) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0) cnt++;
			}
		}
		//cout << cnt << '\n';
		ans = min(ans, cnt);
		return;
	}
	int cctv = get<0>(vec[k]);
	int x = get<1>(vec[k]);
	int y = get<2>(vec[k]);

	vector<vector<int>> board2 = board; // ������ �κ��� -1�� �ٲ���
	switch (cctv) {
	case 1:
		for (int dir = 0; dir < 4; dir++) {
			move(dir, x, y);
			dfs(k + 1);
			board = board2;
		}
		break;
	case 2:
		for (int dir = 0; dir < 2; dir++) {
			move(dir, x, y);
			move(dir + 2, x, y);
			dfs(k + 1);
			board = board2;
		}
		break;
	case 3:
		for (int dir = 0; dir < 4; dir++) {
			move(dir, x, y);
			move((dir + 1)%4, x, y);
			dfs(k + 1);
			board = board2;
		}
		break;
	case 4:
		for (int dir = 0; dir < 4; dir++) {
			move(dir, x, y);
			move((dir+1)%4, x, y);
			move((dir+2)%4, x, y);
			dfs(k + 1);
			board = board2;
		}
		break;
	case 5:
		for (int dir = 0; dir < 4; dir++)
			move(dir, x, y);
		dfs(k + 1);
		board = board2;
		break;
	}

}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0 && board[i][j] != 6) {
				cctv_cnt++;//cctv�� �� ����
				vec.push_back({ board[i][j], i, j });
			}
		}
	}
	dfs(0);
	cout << ans;

}