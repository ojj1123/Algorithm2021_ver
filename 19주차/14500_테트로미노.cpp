#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, m, ans;
int board[505][505];
pair<int, int> shape[19][3] = {
    {{0, 1}, {0, 2}, {0, 3}},  // shape 1
    {{1, 0}, {2, 0}, {3, 0}},
    {{0, 1}, {1, 0}, {1, 1}},  // shpae 2
    {{1, 0}, {2, 0}, {2, 1}},  // shape 3
    {{0, 1}, {0, 2}, {1, 0}},
    {{0, 1}, {1, 1}, {2, 1}},
    {{1, 0}, {1, -1}, {1, -2}},
    {{1, 0}, {2, 0}, {2, -1}},
    {{0, 1}, {0, 2}, {1, 2}},
    {{0, 1}, {1, 0}, {2, 0}},
    {{1, 0}, {1, 1}, {1, 2}},
    {{1, 0}, {1, 1}, {2, 1}},  // shape 4
    {{0, 1}, {1, 0}, {1, -1}},
    {{1, 0}, {1, -1}, {2, -1}},
    {{0, 1}, {1, 1}, {1, 2}},
    {{1, -1}, {1, 0}, {1, 1}},  //shape 5
    {{1, 0}, {2, 0}, {1, 1}},
    {{0, 1}, {0, 2}, {1, 1}},
    {{1, -1}, {1, 0}, {2, 0}},
};
void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> board[i][j];
}
void bfs() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum_cost = 0;
            for (int t = 0; t < 19; t++) {
                int tmp = board[i][j];
                for (int p = 0; p < 3; p++) {
                    int nx = i + shape[t][p].first;
                    int ny = j + shape[t][p].second;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
                    tmp += board[nx][ny];
                }
                sum_cost = max(sum_cost, tmp);
            }
            ans = max(ans, sum_cost);
        }
    }
}

void solve() {
    bfs();
    cout << ans;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}