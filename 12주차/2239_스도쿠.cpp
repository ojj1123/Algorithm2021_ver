#include <bits/stdc++.h>
using namespace std;

bool isused1[9][10]; // 가로
bool isused2[9][10]; // 세로
bool isused3[9][10]; // 3 x 3
int zeroX[100], zeroY[100];
int board[9][9];
int zeroCnt, k;

int box(int x, int y) {
	x = x / 3;
	y = y / 3;
	return 3 * x + y;
}
void solve(int cnt) {
	int x = zeroX[cnt], y = zeroY[cnt];
	if (k == 1) return;
	if (cnt == zeroCnt) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) cout << board[i][j];
			cout << '\n';
		}
		k++;
		return;
	}
	int boxNum = box(x, y);
	for (int t = 1; t <= 9; t++) {
		if (!isused1[x][t] && !isused2[y][t] && !isused3[boxNum][t]) {
			isused1[x][t] = 1;
			isused2[y][t] = 1;
			isused3[boxNum][t] = 1;
			board[x][y] = t;
			solve(cnt + 1);
			isused1[x][t] = 0;
			isused2[y][t] = 0;
			isused3[boxNum][t] = 0;
			board[x][y] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 9; i++) {
		string tmp; cin >> tmp;
		for (int j = 0; j < 9; j++) {
			board[i][j] = tmp[j] - '0';
			int boxNum = box(i, j);
			if (board[i][j]) {
				isused1[i][board[i][j]] = 1;
				isused2[j][board[i][j]] = 1;
				isused3[boxNum][board[i][j]] = 1;
			}
			else {
				zeroX[zeroCnt] = i;
				zeroY[zeroCnt++] = j;
			}
		}
	}
	solve(0);
}