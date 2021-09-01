#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, m, s, e;
int arr[2002];
int dp[2002][2002];

void init() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++) dp[i][i] = 1;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    cin >> m;
}
int solution(int st, int en, int mode) {
    if (dp[st][en] != -1) return dp[st][en];
    if (mode && st == en) return 1;
    if (!mode && st + 1 == en) return arr[st] == arr[en];
    if (arr[st] != arr[en])
        return dp[st][en] = 0;
    else {
        int ret = solution(st + 1, en - 1, mode) && (arr[st] == arr[en]);
        return dp[st][en] = ret;
    }
}
void solve() {
    while (m--) {
        cin >> s >> e;
        cout << solution(s, e, (e - s + 1) % 2) << endl;
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}