// 이 그리디 알고리즘은 항상 성립하는가?
// 동전이 배수가 아닐 경우를 생각해보자.
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, k, ans;
int arr[11];
void init() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
}
void solve() {
    int tmp = k;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] <= k) {
            ans += k / arr[i];
            k %= arr[i];
        }
        if (k == 0) break;
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}