#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define X first
#define Y second

int board[1002][1002];
bool vis1[1002];
bool vis2[1002];
int n, m, v;//������ ����, ������ ����, ������ ������ ��ȣ

void DFS(int v) {
	vis1[v] = 1;
	cout << v << " ";
	for (int i = 1; i <= n; i++) {
		if (board[v][i] != 1 || vis1[i]) continue;
		DFS(i);
	}
}
// DFS stack���� ����
// void DFS(int v) {
// 	stack<int> S;
// 	S.push(v);
// 	vis1[v] = 1;
// 	cout << v << " ";
// 	while (!S.empty()) {
// 		int cur = S.top();
// 		bool flag = false;
// 		for (int i = 1; i <= n; i++) {
// 			if (board[cur][i] != 1 || vis1[i]) continue;
// 			cout << i << " ";
// 			vis1[i] = 1;
// 			flag = true;
// 			S.push(i);
// 			break;
// 		}
// 		if (!flag) S.pop();
// 	}
// }
void BFS(int v) {
	queue<int> Q;
	Q.push(v);
	vis2[v] = 1;
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		cout << cur << " ";
		for (int i = 1; i <= n; i++) {
			if (board[cur][i] != 1 || vis2[i]) continue;
			vis2[i] = 1;
			Q.push(i);
		}
	}
}

int main() {
	FAST;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		board[x][y] = board[y][x] = 1;
	}
	DFS(v);
	cout << "\n";
	BFS(v);
	return 0;
}
// �׷��� ���� - ��������Ʈ�� ������ķ� ��������
// https://gpfatp.blogspot.com/2018/11/boj-1260-dfs-bfs.html
// https://mygumi.tistory.com/102 DFS stack ���� �ڵ�