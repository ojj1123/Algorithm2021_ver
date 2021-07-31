#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
const int INF = 1e9 + 3;
int n, m, st, en;
vector<pair<int, int>> board[1001];
int d[1001];
int path[1001];
vector<int> res;
void init() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        board[a].push_back({b, c});
    }
    cin >> st >> en;
    fill(d, d + n + 1, INF);
}
void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    d[start] = 0;
    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (d[now] < dist) continue;
        for (int i = 0; i < board[now].size(); i++) {
            int next = board[now][i].first;
            int cost = dist + board[now][i].second;
            if (d[next] > cost) {
                d[next] = cost;
                pq.push({-cost, next});
                path[next] = now;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    dijkstra(st);
    cout << d[en] << endl;
    int tmp = en;
    while (tmp) {
        res.push_back(tmp);
        tmp = path[tmp];
    }
    cout << res.size() << endl;
    for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << ' ';
    return 0;
}