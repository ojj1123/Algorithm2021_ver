#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

bool vis[502][502];
int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int picCnt, res;
int main() {
	FAST;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	queue<pair<int, int>> Q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> v[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] && v[i][j]) {
				Q.push({ i,j });
                vis[i][j] = 1;//
				picCnt++;
				int temp = 0;
				while (!Q.empty()) {
					temp++;//난 이거의 위치 때문에 틀림
					pair<int, int> cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] || v[nx][ny] != 1) continue;
						vis[nx][ny] = 1;
						Q.push({ nx,ny });
                        // 여기에 temp를 둠
					}
				}
				res = res < temp ? temp : res;
			}
		}
	}
	cout << picCnt << "\n" << res;
	return 0;
}