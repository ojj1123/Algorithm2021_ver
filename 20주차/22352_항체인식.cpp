// flood fill
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, m;
int board[32][32], test[32][32];
bool vis[32][32];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> board[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> test[i][j];
}
void solve() {
    bool inject = false;
    for (int i = 0; i < n; i++) {
        if (inject) break;
        for (int j = 0; j < m; j++) {
            if (vis[i][j] || board[i][j] == test[i][j]) continue;
            queue<pair<int, int>> q;
            int num = board[i][j];
            q.push({i, j});
            inject = true;
            vis[i][j] = 1;
            board[i][j] = test[i][j];
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                int cx = cur.first, cy = cur.second;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cx + dx[dir];
                    int ny = cy + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || board[nx][ny] != num) continue;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                    board[nx][ny] = test[i][j];
                }
            }
            if (inject) break;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != test[i][j]) {
                cout << "NO";
                return;
            }
        }
    }
    cout << "YES";
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}