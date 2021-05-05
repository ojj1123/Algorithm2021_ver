// 1697_숨바꼭질 문제와 유사함.
#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define X first
#define Y second

int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int main() {
	FAST;
	int t; cin >> t;
	while (t--) {
		int l; cin >> l;
		int fx, fy, lx, ly;
		cin >> fx >> fy >> lx >> ly;
		int dist[302][302];
		for (int i = 0; i < l; i++) fill(dist[i], dist[i] + 301, -1);
		queue<pair<int, int>> Q;
		Q.push({ fx, fy });
		dist[fx][fy] = 0;
		while (!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
				if (dist[nx][ny] != -1) continue;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				Q.push({ nx,ny });
			}
		}
		cout << dist[lx][ly];
		cout << "\n";
	}
	return 0;
}