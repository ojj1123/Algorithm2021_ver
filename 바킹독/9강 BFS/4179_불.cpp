#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define X first
#define Y second

string board[1002];
int fire[1002][1002];
int hoon[1002][1002];
int r, c;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	FAST;
	cin >> r >> c;//행 열
	queue<pair<int, int>> Q1, Q2;
	for (int i = 0; i < r; i++) {
		fill(fire[i], fire[i] + c, -1);
		fill(hoon[i], hoon[i] + c, -1);
	}
	for (int i = 0; i < r; i++) cin >> board[i];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'F') {
				Q1.push({ i,j });
				fire[i][j] = 0;
			}
			if (board[i][j] == 'J') {
				Q2.push({ i,j });
				hoon[i][j] = 0;
			}
		}
	}
	// for (int i = 0; i < r; i++) {
	// 	for (int j = 0; j < c; j++) {
	// 		char ch;
	// 		cin >> ch;
	// 		if (ch != 'F') {
	// 			fire[i][j] = -1;
	// 			if (ch == 'J') Q2.push({ i,j });
	// 		}
	// 		if (ch != 'J') {
	// 			hoon[i][j] = -1;
	// 			if (ch == 'F') Q1.push({ i,j });
	// 		}
	// 	}
	// }
	while (!Q1.empty()) {//fire
		auto cur = Q1.front(); Q1.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (fire[nx][ny] >= 0 || board[nx][ny]=='#') continue;
			fire[nx][ny] = fire[cur.X][cur.Y] + 1;
			Q1.push({ nx,ny });
		}
	}
	while (!Q2.empty()) {//hoon
		auto cur = Q2.front(); Q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
				cout << hoon[cur.X][cur.Y] + 1;
				return 0;
			}
			if (hoon[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			if (fire[nx][ny]!=-1 && hoon[cur.X][cur.Y] + 1 >= fire[nx][ny]) continue;
			hoon[nx][ny] = hoon[cur.X][cur.Y] + 1;
			Q2.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE";
	//int ans = -1;
	//for (int i = 0; i < r; i++) {
	//	for (int j = 0; j < c; j++) {
	//		if ((i > 0 && i < r - 1) && (j > 0 && j < c - 1)) continue;
	//		ans = max(ans, hoon[i][j]);
	//	}
	//}
	//if (ans == -1) cout << "IMPOSSIBLE";
	//else cout << ans + 1;
	return 0;
}
// 왜 내가짠 코드는 메모리 초과가 나지?