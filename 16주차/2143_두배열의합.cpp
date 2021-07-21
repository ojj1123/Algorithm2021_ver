#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int t, n, m;
ll res; // 오버플로우남.. 그냥 다 long long 으로 타입 정하자..
int a[1002];
int b[1002];
vector<int> aa, bb;
void init()
{
    cin >> t;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        a[i] = a[i - 1] + tmp;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int tmp;
        cin >> tmp;
        b[i] = b[i - 1] + tmp;
    }
    for (int cnt = 1; cnt <= n; cnt++)
    {
        for (int i = 0; i <= n - cnt; i++)
        {
            aa.push_back(a[i + cnt] - a[i]);
        }
    }
    for (int cnt = 1; cnt <= m; cnt++)
    {
        for (int i = 0; i <= m - cnt; i++)
        {
            bb.push_back(b[i + cnt] - b[i]);
        }
    }
}
void solve()
{
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());

    int aaSize = aa.size();
    int bbSize = bb.size();
    res = 0;
    for (int i = 0; i < aaSize; i++)
    {
        auto low = lower_bound(bb.begin(), bb.end(), t - aa[i]);
        auto up = upper_bound(bb.begin(), bb.end(), t - aa[i]);
        res += up - low;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    cout << res;
}