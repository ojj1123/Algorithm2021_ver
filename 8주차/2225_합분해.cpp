#include <bits/stdc++.h>
using namespace std;
#define N 1000000000
int n, k;
int dp[210][210];
int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) dp[i][1] = 1;
	for (int j = 1; j <= k; j++) {
		dp[0][j] = 1;
		dp[1][j] = j; // 기저
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			for (int a = 0; a <= i; a++) {
				dp[i][j] += dp[a][j - 1] % N;
				dp[i][j] %= N;
			}
		}
	}
	cout << dp[n][k] % N;
}