#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, m, mid, ans;
bool board[102][102];
void init() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        board[a][b] = 1;
    }
    mid = (1 + n) / 2;
}
void floydWarshall() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (board[i][k] && board[k][j]) board[i][j] = 1;
            }
        }
    }
}
void solve() {
    floydWarshall();
    for (int i = 1; i <= n; i++) {
        int cnt1 = 0, cnt2 = 0;
        for (int j = 1; j <= n; j++) {
            if (board[i][j]) cnt1++;
            if (board[j][i]) cnt2++;
        }
        if (cnt1 >= mid) ans++;
        if (cnt2 >= mid) ans++;
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}