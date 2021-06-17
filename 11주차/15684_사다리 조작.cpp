#include <bits/stdc++.h>
using namespace std;
bool vis[32][12];
int n, m, h, a, b, ans = 10;
bool flag = 0;
bool ladder_game() {
	for (int i = 1; i < n; i++) {
		int cur = i;
		for (int j = 1; j <= h; j++) {
			if (vis[j][cur]) cur++; // cur에서 다음으로 가는 길이 있는 경우 그곳으로 이동
			else if (vis[j][cur-1]) cur--;
		}
		if (cur != i) return false;
	}
	return true;
}
void solve(int idx, int cnt) {
	if (cnt == 4) {
		return;
	}
	if (ladder_game()) { //여기를 안거치면 -1 출력
		flag = 1;
		ans = min(ans, cnt);
		return;
	}
	for (int i = idx; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (vis[i][j] || vis[i][j+1] || vis[i][j-1]) continue;
			vis[i][j] = 1;
			solve(i, cnt + 1); // 중복을 제외해줘야함.
			vis[i][j] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		vis[a][b] = true;
	}
	solve(1, 0);
	if (flag) cout << ans;
	else cout << -1;
}