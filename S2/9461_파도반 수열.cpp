#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

long long  dp[101];
int main() {
	FAST;
	long long t;
	cin >> t;
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = 2;
	while (t--) {
		int n;
		cin >> n;
		if (!dp[n]) {
			for (int i = 5; i <= n; i++)
				dp[i] = dp[i - 1] + dp[i - 5];
		}
		cout << dp[n];
		cout << "\n";
	}
	return 0;
}