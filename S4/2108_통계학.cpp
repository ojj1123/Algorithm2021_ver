#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int cnt[8001];
int main() {
	FAST;
	int n;
	cin >> n;
	vector<int> vec(n);
	double sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		sum += vec[i];
		cnt[4000 + vec[i]]++;
	}
	sort(vec.begin(), vec.end());
	int center_Idx = vec.size() / 2; // center
	int mode = 0, mode_val;
	for (int i = 0; i < 8001; i++) {
		if (cnt[i] > mode) mode = cnt[i], mode_val = i - 4000;
	}
	int tmpCnt = 0;
	for (int i = 0; i < 8001; i++) {
		if (cnt[i] == mode) tmpCnt++;
		if (tmpCnt == 2) {
			mode_val = i - 4000;
			break;
		}
	}
	cout << round(sum / n) << "\n";
	cout << vec[center_Idx] << "\n";
	cout << mode_val << "\n";
	cout << vec[n - 1] - vec[0] << "\n";
	return 0;
}