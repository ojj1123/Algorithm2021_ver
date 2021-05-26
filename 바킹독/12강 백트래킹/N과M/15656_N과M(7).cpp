#include <bits/stdc++.h>
using namespace std;
int arr[10];
int ans[10];
int n, m;

void solve(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		ans[k] = arr[i];
		solve(k + 1);
	}
}
int main(void) {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	solve(0);
}