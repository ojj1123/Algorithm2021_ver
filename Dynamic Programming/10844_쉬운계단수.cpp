// 기저 상황이나 조건을 꼼꼼하게 따져주자.
// 틀리는데는 분명히 이유가 있다. 이 문제를 틀린 이유는 조건을 제대로 확인하지 않았기 때문이다.
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

using ll = long long;
const ll MOD = 1e9;
ll n, ans;
ll dp[102][12];
void solve() {
    fill(dp[1], dp[1] + 10, 1);

    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1] % MOD;
        for (int j = 1; j < 10; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
    }
    for (int i = 1; i < 10; i++) {
        ans %= MOD;
        ans += dp[n][i] % MOD;
    }
    cout << ans % MOD;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    solve();
    return 0;
}