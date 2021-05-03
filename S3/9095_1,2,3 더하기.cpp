#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int dp[11];
int main() {
	FAST;
	int t;
	cin >> t;
	dp[1] = 1, dp[2] = 2, dp[3] = 4;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 4; i <= n; i++)
			dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
		cout << dp[n]<<"\n";
	}
	return 0;
}