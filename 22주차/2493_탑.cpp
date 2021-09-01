#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int sz = 500002;
int n;
int arr[sz];
int res[sz];
void init() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
}
void solve() {
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        while (!st.empty()) {
            if (arr[st.top()] >= arr[i]) {
                res[i] = st.top();
                break;
            }
            st.pop();
        }
        st.push(i);
    }
    for (int i = 1; i <= n; i++) cout << res[i] << ' ';
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}