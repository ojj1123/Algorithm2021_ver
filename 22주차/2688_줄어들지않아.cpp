#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

long long dp[66][10];
void solve() {
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n;
    fill(dp[1], dp[1] + 10, 1);
    for (int i = 2; i <= 65; i++) {
        for (int j = 0; j < 10; j++) dp[i][0] += dp[i - 1][j];
        for (int j = 1; j < 10; j++) dp[i][j] = dp[i][j - 1] - dp[i - 1][j - 1];
    }
    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n + 1][0] << endl;
    }
    return 0;
}