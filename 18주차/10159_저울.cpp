#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, m;
bool board[101][101];
void init() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        board[a][b] = 1;  // a > b
    }
}
void floydWarshall() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (board[i][k] && board[k][j]) board[i][j] = 1;  // 비교 할 수 있음
            }
        }
    }
}
void solve() {
    floydWarshall();
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (!board[i][j] && !board[j][i]) cnt++;
        }
        cout << cnt << endl;
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}