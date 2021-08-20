#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int INF = 100;
int n, a, b;
int board[52][52];
vector<int> res, tmp;
void init() {
    cin >> n;
    for (int i = 1; i <= n; i++) fill(board[i], board[i] + n + 1, INF);
    for (int i = 1; i <= n; i++) board[i][i] = 0;
    while (1) {
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        board[a][b] = board[b][a] = 1;
    }
}
void solve() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (board[i][j] > board[i][k] + board[k][j]) board[i][j] = board[i][k] + board[k][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            mx = max(mx, board[i][j]);
        }
        tmp.push_back(mx);
    }
    int ans = *min_element(tmp.begin(), tmp.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (ans == tmp[i]) {
            cnt++;
            res.push_back(i + 1);
        }
    }
    cout << ans << ' ' << cnt << endl;
    for (int i = 0; i < cnt; i++) cout << res[i] << ' ';
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}