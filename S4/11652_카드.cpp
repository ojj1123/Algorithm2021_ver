#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
constexpr int N = 100000;

int main() {
	FAST;
	int n;
	long long result;
	cin >> n;
	vector<long long> vec(n);
	vector<int> cnt(N, 0);

	for (int i = 0; i < n; i++) cin >> vec[i];
	sort(vec.begin(), vec.end());

	int idx = 0;
	int count = 1;
	long long temp = vec[0];
	for (int i = 1; i < n; i++) {
		if (temp == vec[i]) {
			count++;
			cnt[idx] = count;
		}
		else {
			idx++;
			count = 1;
			temp = vec[i];
		}
	}
	int max_cnt = 0;
	for (int i = 0; i < N; i++) {
		if (cnt[i]) {
			if (max_cnt < cnt[i]) max_cnt = cnt[i];
		}
	}
	for (int i = 0; i < N; i++) {
		if (cnt[i] == max_cnt) {
			idx = i;
			break;
		}
	}
	temp = vec[0];
	int change_idx = 0;
	for (int i = 1; i < n; i++) {
		if (idx == change_idx) {
			result = temp;
			break;
		}
		else if (temp != vec[i]) {
			change_idx++;
			temp = vec[i];
		}
	}
	cout << result;
	return 0;
}