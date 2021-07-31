#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
const int INF = 1e9 + 3;
int n, m, st, en;
vector<pair<int, int>> board[1001];
int d[1001];
bool selected[1001];
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
    d[start] = 0;
    for (int i = 1; i <= n; i++) {
        int min_idx = -1, min_dist = INF;
        for (int j = 1; j <= n; j++) {
            if (selected[j]) continue;
            if (min_dist > d[j]) {
                min_dist = d[j];
                min_idx = j;
            }
        }
        selected[min_idx] = 1;
        for (int j = 0; j < board[min_idx].size(); j++) {
            int next = board[min_idx][j].first;
            int cost = min_dist + board[min_idx][j].second;
            if (selected[next]) continue;
            if (d[next] > cost) {
                path[next] = min_idx;
                d[next] = cost;
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