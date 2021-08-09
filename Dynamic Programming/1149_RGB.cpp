#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int INF = 1e7;
int n;
int rgb[1002][4];
int dp[1002][4];
void init() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 3; j++) cin >> rgb[i][j];
}
void solve() {
    int ans = INF;
    for (int st = 1; st <= 3; st++) {
        for (int i = 1; i <= 3; i++) {
            if (st == i)
                dp[1][i] = rgb[1][i];
            else
                dp[1][i] = INF;
        }
        for (int i = 2; i <= n; i++) {
            dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + rgb[i][1];
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + rgb[i][2];
            dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][3];
        }
        for (int i = 1; i <= 3; i++) {
            ans = min(ans, dp[n][i]);
        }
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}