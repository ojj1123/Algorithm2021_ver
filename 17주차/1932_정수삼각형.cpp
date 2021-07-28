#include <bits/stdc++.h>
using namespace std;

int n, ans;
int arr[502][502];
int dp[502][502];
void init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> arr[i][j];
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1)
                dp[i][j] = dp[i - 1][j] + arr[i][j];
            else if (j == i)
                dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
            else
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}
int main()
{
    init();
    solve();
}