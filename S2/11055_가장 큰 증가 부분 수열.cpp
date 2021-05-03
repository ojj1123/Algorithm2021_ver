#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int arr[1005];
int dp[1005]; // sum
int main() {
	FAST;
	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sum = dp[0];
	for (int i = 0; i < n; i++) {
		dp[i] = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] < dp[j] + arr[i])
					dp[i] = dp[j] + arr[i];
			}
		}
		sum = max(sum, dp[i]);
	}
	cout << sum;
	return 0;
}