/*
    주석 처리한 코드 : 메모리 초과 아슬아슬한 코드
    주석 없는 코드 : 메모리를 최소한으로 사용한 코드
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

// const int sz = 1e5 + 2;
// const int MAX = 1e6;
// int dp[sz][3];
// short board[sz][3];
// int n;
// int a, b, c;
// int mxAns, mnAns;
// void init() {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < 3; j++) cin >> board[i][j];
// }
// void solve() {
//     for (int st = 0; st < 3; st++) {
//         for (int i = 0; i < 3; i++)
//             dp[0][i] = st == i ? board[0][i] : 0;
//         for (int i = 1; i < n; i++) {
//             dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + board[i][0];
//             dp[i][1] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) + board[i][1];
//             dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + board[i][2];
//         }
//         for (int i = 0; i < 3; i++)
//             mxAns = max(mxAns, dp[n - 1][i]);
//     }
//     mnAns = MAX;
//     for (int st = 0; st < 3; st++) {
//         for (int i = 0; i < 3; i++)
//             dp[0][i] = st == i ? board[0][i] : MAX;
//         for (int i = 1; i < n; i++) {
//             dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + board[i][0];
//             dp[i][1] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + board[i][1];
//             dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + board[i][2];
//         }
//         for (int i = 0; i < 3; i++)
//             mnAns = min(mnAns, dp[n - 1][i]);
//     }
//     cout << mxAns << ' ' << mnAns;
// }
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // init();
    // solve();
    int n;
    int a[3], t[3];
    int mx[3], mn[3];
    cin >> n;
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
        mx[i] = mn[i] = a[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> a[0] >> a[1] >> a[2];
        t[0] = max(mx[0], mx[1]) + a[0];
        t[1] = max(mx[0], max(mx[1], mx[2])) + a[1];
        t[2] = max(mx[1], mx[2]) + a[2];
        mx[0] = t[0];
        mx[1] = t[1];
        mx[2] = t[2];

        t[0] = min(mn[0], mn[1]) + a[0];
        t[1] = min(mn[0], min(mn[1], mn[2])) + a[1];
        t[2] = min(mn[1], mn[2]) + a[2];
        mn[0] = t[0];
        mn[1] = t[1];
        mn[2] = t[2];
    }
    int ans1 = max(mx[0], max(mx[1], mx[2]));
    int ans2 = min(mn[0], min(mn[1], mn[2]));
    cout << ans1 << ' ' << ans2;

    return 0;
}