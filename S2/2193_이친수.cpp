#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

long long dp[91];
int main() {
	FAST;
	int n;
	cin >> n;
	dp[1] = dp[2] = 1;
	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[n];
	return 0;
}