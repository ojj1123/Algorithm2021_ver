#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main() {
	FAST;
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	int start = 0, end = 0, sum = 0, res = 0;
	while (1) {
		if (sum >= m)sum -= arr[start++];
		else if (end == n) break;
		else sum += arr[end++];
		if (sum == m) res++;
	}
	cout << res;
	return 0;
}