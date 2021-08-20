#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int sz = 200002;
int n, m;
vector<int> board[sz];
int vis[sz];            // 방문 여부
int currentBelive[sz];  // 현재 주변에 루머를 믿는 사람의 수
int around[sz];         // 주변 사람 중 절반
queue<int> q;
void init() {
    cin >> n;
    fill(vis, vis + n + 1, -1);
    for (int i = 1; i <= n; i++) {
        int a;
        while (1) {
            cin >> a;
            if (a == 0) break;
            board[i].push_back(a);
            board[a].push_back(i);
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        q.push(a);
        vis[a] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int tmp = board[i].size();
        around[i] = tmp % 2 == 0 ? tmp / 2 : tmp / 2 + 1;
    }
}
void bfs() {
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < board[cur].size(); i++) {
            int nx = board[cur][i];
            if (vis[nx] != -1) continue;
            currentBelive[nx]++;
            if (currentBelive[nx] < around[nx]) continue;
            vis[nx] = vis[cur] + 1;
            q.push(nx);
        }
    }
}
void solve() {
    bfs();
    for (int i = 1; i <= n; i++) cout << vis[i] << ' ';
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}