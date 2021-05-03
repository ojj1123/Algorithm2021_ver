#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int ab[505];
int dp[505];
int main() {
	FAST;
	int n, tempA, maxA = -1, maxN = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tempA;
		cin >> ab[tempA];
		maxA = maxA < tempA ? tempA : maxA;
	}
	for (int i = 1; i <= maxA; i++) {
		if (ab[i] != 0) {
			if (dp[i] == 0) dp[i] = 1;
			for (int j = 1; j < i; j++) {
				if (ab[j] != 0) {
					if (ab[i] > ab[j] && dp[i] < dp[j] + 1)
						dp[i] = dp[j] + 1;
				}
			}
		}
		maxN = max(dp[i], maxN);
	}
	cout << n - maxN;
	return 0;
}