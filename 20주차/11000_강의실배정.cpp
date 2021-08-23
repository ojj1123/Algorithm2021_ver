#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, ans;
vector<pair<int, int>> v;
void init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());  // 먼저 시작하는 순으로 정렬
}
void solve() {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < v.size(); i++) {
        if (i == 0) {
            ans++;
        } else {
            if (q.top() > v[i].first) {
                ans++;
            } else {
                q.pop();
            }
        }
        q.push(v[i].second);
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}