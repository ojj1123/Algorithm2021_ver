#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int INF = 1 << 31 - 1;
int n;
int arr[505][2];
int dp[505][505];
void init() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1];
    memset(dp, -1, sizeof(dp));
}
int solve(int st, int en) {
    if (st == en) return 0;
    int mn = INF;
    if (dp[st][en] != -1) return dp[st][en];
    for (int i = st; i < en; i++) {
        mn = min(mn, solve(st, i) + solve(i + 1, en) + arr[st][0] * arr[i][1] * arr[en][1]);
    }
    return dp[st][en] = mn;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    cout << solve(0, n - 1);
    return 0;
}