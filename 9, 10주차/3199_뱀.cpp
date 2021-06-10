#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[105][105];
bool vis[105][105];
int n, k, l; // 보드크기, 사과개수, 방향전환횟수
char act[10002];
deque<pair<int, int>> snake;
int cnt;

bool outofbound(int x, int y) {
	if (x<1 || x>n || y<1 || y>n) return 1;
	return 0;
}
pair<int, int> direction(int posx, int posy, int d) { // 각 좌표의 방향에 따른 이동좌표
	pair<int, int> res;
	switch (d) {
	case 0: // 오른
		res = { posx, posy + 1 };
		break;
	case 1: // 아래
		res = { posx + 1, posy };
		break;
	case 2: // 왼
		res = { posx, posy - 1 };
		break;
	case 3: // 위
		res = { posx - 1, posy };
	}
	return res;
}
void move() {
	snake.push_back({ 1, 1 });
	vis[1][1] = 1;
	int d = 0;
	while (1) {
		cnt++;
		auto head = snake.front();
		int nx ,ny;
		if (act[cnt - 1] == 0) {
			auto newHead = direction(head.X, head.Y, d);
			nx = newHead.X, ny = newHead.Y;
			snake.push_front({ nx, ny });
			if (outofbound(nx, ny) || vis[nx][ny]) return; // 벽이거나 이미 방문했으면
			if (board[nx][ny] == 1) {
				board[nx][ny] = 0; // 사과 없앰
			}
			else {
				auto tail = snake.back();
				vis[tail.X][tail.Y] = 0;
				snake.pop_back();
			}
			vis[nx][ny] = 1;
		}
		else {
			d = act[cnt - 1] == 'D' ? (d + 1) % 4 : (d + 3) % 4;
			auto newHead = direction(head.X, head.Y, d);
			nx = newHead.X, ny = newHead.Y;
			snake.push_front({ nx, ny });
			if (outofbound(nx, ny) || vis[nx][ny]) return; // 벽이거나 이미 방문했으면
			if (board[nx][ny] == 1) {
				board[nx][ny] = 0; // 사과 없앰
			}
			else {
				auto tail = snake.back();
				vis[tail.X][tail.Y] = 0;
				snake.pop_back();
			}
			vis[nx][ny] = 1;
		}
	}

}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	while (k--) {
		int r, c;
		cin >> r >> c;
		board[r][c] = 1;
	}
	cin >> l;
	while (l--) {
		int x;
		char c;
		cin >> x >> c;
		act[x] = c;
	}
	move();
	cout << cnt;
}