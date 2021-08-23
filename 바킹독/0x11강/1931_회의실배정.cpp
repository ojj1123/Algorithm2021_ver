#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, a, b, ans;
pair<int, int> p[100002];
void init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        p[i] = {b, a};  // 끝나는 시간 , 시작 시간
    }
    sort(p, p + n);
}
void solve() {
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            q.push(p[i].first);
            ans++;
        } else {
            if (q.top() <= p[i].second) {
                q.push(p[i].first);
                ans++;
            }
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