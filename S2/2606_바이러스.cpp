// 1926_�׸� ������ ������.
#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int board[102][102];
bool vis[102];
int n, m;//������ ����, ������ ����

int main() {
	FAST;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		board[x][y] = board[y][x] = 1;
	}
	queue<int> Q;
	int cnt = 0;
	Q.push(1);
	vis[1] = 1;
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		cnt++;
		for (int i = 1; i <= n; i++) {
			if (board[cur][i] != 1 || vis[i]) continue;
			vis[i] = 1;
			Q.push(i);
		}
	}
	cout <<cnt-1;
	return 0;
}