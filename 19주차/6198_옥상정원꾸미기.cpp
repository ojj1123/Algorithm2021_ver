#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
const int sz = 80003;
int n;
ll ans;
int h[sz];
int res[sz];
void init() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
}
void solve() {
    stack<pair<int, int>> st;
    for (int i = 1; i <= n; i++) res[i] = n - i;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && st.top().first <= h[i]) {
            res[st.top().second] = i - st.top().second - 1;
            st.pop();
        }
        st.push({h[i], i});
    }
    for (int i = 1; i <= n; i++) ans += (ll)res[i];
    cout << ans;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}