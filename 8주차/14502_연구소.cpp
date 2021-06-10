#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
vector<vector<int>> board(8, vector<int>(8, 0));
vector<vector<int>> board2;
vector<pair<int, int>> emp;
queue<pair<int, int>> virus, virus2;
bool isused[65];
int empSize;
int n, m, ans = -1;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void bfs() {
	while (!virus.empty()) {
		auto cur = virus.front(); virus.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] != 0) continue;
			virus.push({ nx, ny });
			board[nx][ny] = 2;
		}
	}
}
void dfs(int k) {
	if (k == 3) {
		board2 = board; // 3개의 벽을 세워준 것(바이러스 퍼지기 전)
		bfs(); // 바이러스 퍼짐
		virus = virus2;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0) cnt++;
			}
		}
		ans = max(ans, cnt);
		board = board2; // 퍼지기 전으로 돌려줌
		return;
	}
	for (int i = 0; i < empSize; i++) {
		if (!isused[i]) {
			isused[i] = 1;
			board[emp[i].first][emp[i].second] = 1; // 벽으로 바꿔줌
			dfs(k + 1);
			//dfs 가 종료하면
			board[emp[i].first][emp[i].second] = 0; // 빈 곳으로 바꿔줌
			isused[i] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) emp.push_back({ i, j });
			if (board[i][j] == 2) virus.push({ i, j });
		}
	}
	virus2 = virus;
	empSize = emp.size();
	dfs(0);
	cout << ans;
}