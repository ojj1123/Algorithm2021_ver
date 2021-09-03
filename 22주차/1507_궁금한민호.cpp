#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, total;
int board[22][22];
bool vis[22][22];
void init() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
            if (i <= j) continue;
            total += board[i][j];
        }
}
void solve() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j || j == k || k == i) continue;
                if (board[i][j] > board[i][k] + board[k][j]) {
                    cout << -1;
                    return;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i <= j) continue;
            for (int k = 1; k <= n; k++) {
                if (k == i || k == j) continue;
                if (board[i][k] + board[k][j] == board[i][j]) vis[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i <= j) continue;
            if (vis[i][j]) total -= board[i][j];
        }
    }
    cout << total;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}