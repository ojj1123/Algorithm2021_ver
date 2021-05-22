#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
constexpr int N = 1500000;
int dp[N + 2];
int main() {
	FAST;
	int n; cin >> n;
	vector<int> t(n + 5), p(n + 5);
	for (int i = 1; i <= n; i++)
		cin >> t[i] >> p[i];
	int cur_max = 0;
	for (int i = 1; i <= n + 1; i++) {
		cur_max = max(cur_max, dp[i]);
		if (i + t[i] > n + 1) continue;
		dp[i + t[i]] = max(dp[i + t[i]], cur_max + p[i]);
	}
	cout << cur_max;
	return 0;
}