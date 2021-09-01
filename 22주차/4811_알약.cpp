#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

using ll = long long;
int n;
ll dp[35][35];
ll solve(int w, int h) {
    if (w < 1 || h < 1) return 0;
    ll &ref = dp[w][h];
    if (ref != -1) return ref;
    if (w == 1) return ref = 1;
    if (w > h) return ref = solve(w - 1, h);
    if (w <= h) return ref = solve(w - 1, h) + solve(w, h - 1);
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(dp, -1, sizeof(dp));
    while (1) {
        cin >> n;
        if (n == 0) break;
        cout << solve(n, n) << endl;
    }
    return 0;
}