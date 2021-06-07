#include <bits/stdc++.h>
using namespace std;

int first, last, n, s, sum;
int ans = 100002;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> s;
	vector<int> arr(n+2, 0);
	for (int i = 0; i < n; i++) cin >> arr[i];
	while (last <= n) {
		if (s > sum) {
			sum += arr[last++];
		}
		else {
			ans = min(ans, last - first);
			sum -= arr[first++];
		}
	}
	if (ans == 100002) {
		cout << 0;
		return 0;
	}
	cout << ans;
}