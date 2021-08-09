// 문제에서 구하고자 하는 것
// N개의 색으로 구성되어 있는 색상환 (N색상환)에서 어떤 인접한 두 색도 동시에 선택하지 않으면서 서로 다른 K개의 색을 선택하는 경우의 수
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MOD = 1e9 + 3;
int n, k;
int dp[1002][1002];
int solve(int cur, int x) {
    if (cur == 0 || cur < x * 2) return 0;
    if (x == 1) return cur;

    int &ret = dp[cur][x];
    if (ret != -1) return dp[cur][x];

    return ret = (solve(cur - 2, x - 1) + solve(cur - 1, x)) % MOD;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    cout << solve(n, k);
    return 0;
}