#include <bits/stdc++.h>
using namespace std;

int n, ans;
int main()
{
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        a[i] = {tmp, i};
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        if (a[i].second > i)
            ans = max(ans, a[i].second - i);
    }
    cout << ans + 1;
}