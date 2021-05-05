#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int dist[100002];
int n, k;
int main() {
	FAST;
	cin >> n >> k;
	fill(dist, dist + 100001, -1);
	dist[n] = 0;
	queue<int> Q;
	Q.push(n);
	while (dist[k] == -1) { //dist[k]에 방문하면 종료하면 됨.
		int cur = Q.front(); Q.pop();
		for (int nxt : {cur - 1, cur + 1, cur * 2}) {
			if (nxt < 0 || nxt>100000) continue;
			// 범위 설정(범위를 함부로 설정하기 보다는 논리적으로 설정)
			if (dist[nxt] != -1) continue;// 이미 방문함
			dist[nxt] = dist[cur] + 1;
			Q.push(nxt);
		}
	}
	cout << dist[k];
	return 0;
}