#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MOD = 10007;
int n, k;
int dp[1001][1001];
void init() {
    cin >> n >> k;
}
int topDown(int a, int b) {
    int &ret = dp[a][b];
    if (a < 0 || b < 0) return 0;
    if (ret != -1) return ret;
    if (b == a || b == 0) return ret = 1;
    return ret = (topDown(a - 1, b - 1) + topDown(a - 1, b)) % MOD;
}
void bottomUp() {
    for (int i = 0; i <= n; i++)
        dp[i][i] = dp[i][0] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
        }
    }
    cout << dp[n][k] % MOD;
}
void solve() {
    // memset(dp, -1, sizeof(dp));
    // topDown(n, k);
    // cout << dp[n][k];
    bottomUp();
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}