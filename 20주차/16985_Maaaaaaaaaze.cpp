#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int ans = 200;
bool board[5][4][5][5];  // 판의 수(z), 각 판의 경우(회전), 각 판의 x, y
bool isused[5];          // 사용된 판의 여부
vector<pair<int, int>> level;
int vis[5][5][5];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void rotation(int num) {
    for (int z = 0; z < 5; z++)
        for (int x = 0; x < 5; x++)
            for (int y = 0; y < 5; y++)
                board[z][num][x][y] = board[z][num - 1][y][4 - x];  // 1이 들어갈 수 있는 칸, 0이 들어갈 수 없는 칸
}
void init() {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++) cin >> board[i][0][j][k];
    rotation(1);
    rotation(2);
    rotation(3);
}
void bfs() {
    memset(vis, -1, sizeof(vis));
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    vis[0][0][0] = 0;
    if (board[level[4].first][level[4].second][4][4] && board[level[0].first][level[0].second][0][0]) {
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int cx = get<0>(cur);
            int cy = get<1>(cur);
            int cz = get<2>(cur);
            for (int dir = 0; dir < 6; dir++) {
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                int nz = cz + dz[dir];
                if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
                int nextz = level[nz].first;
                int k = level[nz].second;
                if (vis[nx][ny][nz] != -1 || !board[nextz][k][nx][ny]) continue;
                vis[nx][ny][nz] = vis[cx][cy][cz] + 1;
                q.push({nx, ny, nz});
            }
        }
    }
    ans = vis[4][4][4] == -1 ? ans : min(ans, vis[4][4][4]);
}
void solve(int cnt) {
    if (cnt == 5) {
        bfs();
        return;
    }
    for (int b = 0; b < 5; b++) {
        for (int i = 0; i < 4; i++) {
            if (isused[b]) continue;
            isused[b] = 1;
            level.push_back({b, i});
            solve(cnt + 1);
            level.pop_back();
            isused[b] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve(0);
    cout << (ans == 200 ? -1 : ans);
    return 0;
}