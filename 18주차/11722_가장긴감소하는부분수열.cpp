#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, ans;
int a[1001];
int lis[1001];
void init() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}
void solve() {
    ans = 1;
    lis[0] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (lis[ans - 1] < a[i])
            lis[ans++] = a[i];
        else {
            int idx = lower_bound(lis, lis + ans, a[i]) - lis;
            lis[idx] = a[i];
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