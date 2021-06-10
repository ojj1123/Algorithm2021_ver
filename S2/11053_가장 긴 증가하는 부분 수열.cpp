#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main() {
	FAST;
	int n, max_length = 1;
	cin >> n;

	int arr[1000] = { 0, };
	int dp[1000] = { 0, };

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		max_length = max(max_length, dp[i]);
	}
	cout << max_length;
	return 0;
}
// https://lmcoa15.tistory.com/10