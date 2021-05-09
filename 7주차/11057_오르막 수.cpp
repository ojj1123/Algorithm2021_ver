#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int dp[1002][11];
int main() {
	FAST;
	int n;
	cin >> n;
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	int sum = 10;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) dp[i][j] = sum % 10007;
			else {
				dp[i][j] = (dp[i][j - 1] - dp[i - 1][j - 1] + 10007) % 10007;
				sum += dp[i][j] % 10007;
			}
		}
	}
	cout << sum%10007;
	return 0;
}