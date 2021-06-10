#include <bits/stdc++.h>
using namespace std;

int n, m, k, cnt, offcnt;
string board[52];
vector<string> vec[50];
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];
	cin >> k;
	for (int i = 0; i < n; i++) {
		offcnt = 0;
		for (int j = 0; j < m; j++)
			if (board[i][j] == '0') offcnt++;
		if (offcnt <= k) {
			if ((offcnt % 2 == 0 && k % 2 != 0) || (offcnt % 2 != 0 && k % 2 == 0)) continue;
			if (cnt == 0) vec[cnt++].push_back(board[i]);
			else {
				bool flag = 1;
				for (int a = 0; a < cnt; a++) {
					if (vec[a].front() == board[i]) { // 같은 것이 있으면
						vec[a].push_back(board[i]);
						flag = 0;
						break;
					}
				}
				if (flag) vec[cnt++].push_back(board[i]); // 같은 것이 없으면
			}
		}
	}
	int ans = 0;
	for (int i = 0; vec[i].size() != 0; i++) ans=max(ans, (int)vec[i].size());
	cout << ans;
}