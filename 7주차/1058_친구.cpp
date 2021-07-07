#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int board[52][52];
int n, ans, cnt;
void floydWarshall() {
	for (int k = 0; k < n; k++) // 거쳐가는 정점
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)	{
				if (i == j || j == k || i == k)
					continue;
				else if (board[i][j] > board[i][k] + board[k][j])
					board[i][j] = board[i][k] + board[k][j];
			}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < tmp.size(); j++) {
			if (i == j) board[i][j] = 0;
			else board[i][j] = tmp[j] == 'Y' ? 1 : INF;
		}
	}
	floydWarshall();
	for (int i = 0; i < n; i++) {
		cnt = 0;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			else if (board[i][j] <= 2) cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}