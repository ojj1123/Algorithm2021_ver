#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, len1, len2, ans;
int a[1001];
int lf[1001], rt[1001];
void init() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}
void solve() {
    for (int i = 0; i < n; i++) {
        fill(lf, lf + n, 0);
        fill(rt, rt + n, 0);
        len1 = len2 = 0;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                if (len1 == 0)
                    lf[len1++] = a[j];
                else {
                    if (lf[len1 - 1] < a[j])
                        lf[len1++] = a[j];
                    else {
                        int idx = lower_bound(lf, lf + len1, a[j]) - lf;
                        lf[idx] = a[j];
                    }
                }
            }
        }
        for (int j = n - 1; j > i; j--) {
            if (a[i] > a[j]) {
                if (len2 == 0)
                    rt[len2++] = a[j];
                else {
                    if (rt[len2 - 1] < a[j])
                        rt[len2++] = a[j];
                    else {
                        int idx = lower_bound(rt, rt + len2, a[j]) - rt;
                        rt[idx] = a[j];
                    }
                }
            }
        }
        ans = max(ans, len1 + len2 + 1);
    }

    cout << ans;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}