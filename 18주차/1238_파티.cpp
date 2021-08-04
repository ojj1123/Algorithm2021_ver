#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int INF = 1e6;
int n, m, x, ans;
vector<pair<int, int>> board[1001];
int d[1001];
vector<int> toHome;
void init() {
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        board[a].push_back({b, c});
    }
}
void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    fill(d, d + n + 1, INF);
    pq.push({0, start});
    d[start] = 0;
    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now] < dist) continue;
        for (int i = 0; i < board[now].size(); i++) {
            int next = board[now][i].first;
            int cost = board[now][i].second + dist;
            if (d[next] > cost) {
                d[next] = cost;
                pq.push({-cost, next});
            }
        }
    }
}
void solve() {
    dijkstra(x);
    for (int i = 1; i <= n; i++) toHome.push_back(d[i]);
    for (int i = 1; i <= n; i++) {
        int sum = toHome[i - 1];
        dijkstra(i);
        sum += d[x];
        ans = max(ans, sum);
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}