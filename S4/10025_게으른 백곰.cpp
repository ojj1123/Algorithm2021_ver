#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
constexpr auto N = 1000001;

vector<int> vec(N);
int main() {
	FAST;
	int n, k, g, x, end_Idx = -1;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> g >> x;
		vec[x] = g;
		if (end_Idx < x) end_Idx = x;
	}
	int max_sum = 0;
	int window_sum = 0;
	int window_start = 0;

	if (end_Idx <= k) {
		for (int i = 0; i <= end_Idx; i++)
			if (vec[i] != 0) max_sum += vec[i];
	}
	else {
		for (int i = 0; i < k; i++)
			window_sum += vec[i];
		for (int i = k; i < end_Idx; i++) {
			window_sum += vec[i];
			max_sum = (max_sum > window_sum ? max_sum : window_sum);
			if (i > 2 * k) {
				window_sum -= vec[window_start];
				window_start++;
			}
		}
	}
	cout << max_sum;

	return 0;
}