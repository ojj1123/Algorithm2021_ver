#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
constexpr int N = 1000000;

int main() {
	FAST;
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	int start = 0, sum = 0, res = 0;
	for (int i = 0; i < n; i++) {
		if (i < k) {
			sum += arr[i];
			res = sum;
		}
		else {
			sum += arr[i];
			sum -= arr[start++];
			res = max(res, sum);
		}
	}
	cout << res;
	return 0;
}