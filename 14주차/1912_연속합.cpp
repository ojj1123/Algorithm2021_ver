#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, sum = -1005;
int arr[100002];
int dp[100002];
void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        sum = max(sum, dp[i]);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    input();
    solve();
    cout << sum;
}