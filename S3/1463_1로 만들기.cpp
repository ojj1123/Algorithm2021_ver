#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
constexpr int N = 1000000;

int dp[N+1];
int main() {
	FAST;
	int n;
	cin >> n;
	dp[1] = 0, dp[2] = 1, dp[3] = 1;
	for (int i = 4; i <= n; i++) {
		if (i % 2 != 0 && i % 3 != 0) {
			dp[i] = dp[i - 1] + 1;
		}
		else {
			if (i % 2 == 0 && i % 3 != 0)
				dp[i] = min(dp[i - 1], dp[i / 2]) + 1;
			else if (i % 2 != 0 && i % 3 == 0)
				dp[i] = min(dp[i - 1], dp[i / 3]) + 1;
			else 
				dp[i] = min(min(dp[i / 2], dp[i / 3]), dp[i - 1]) + 1;
		}
	}
	cout << dp[n];
	return 0;
}