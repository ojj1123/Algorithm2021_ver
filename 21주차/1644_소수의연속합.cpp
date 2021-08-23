// 투 포인터 다시 복습해야함.
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int sz = 4000002;
int n, ans;
vector<int> vec;
bool prime[sz];
void solve() {
    cin >> n;
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            prime[j] = 1;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (!prime[i]) vec.push_back(i);
    }
    // for (int i = 0; i < vec.size(); i++) cout << vec[i] << ' ';
    int st = 0, en = 0, sum = 0;
    int len = vec.size();
    while (st <= en) {
        if (sum >= n)
            sum -= vec[st++];
        else if (en == len)
            break;
        else
            sum += vec[en++];
        if (sum == n) ans++;
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}