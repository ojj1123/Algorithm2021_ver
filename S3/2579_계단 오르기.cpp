#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int dp[302];
int main() {
	FAST;
	int n;
	cin >> n;
	vector<int> arr(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> arr[i];
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	int res = 0;
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
	}
	cout << dp[n];
	return 0;
}