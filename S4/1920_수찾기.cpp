#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int BSearch(vector<int> &v, int target) {
	int low = 0;
	int high = v.size() - 1;
	int mid;

	while (low <= high) {
		mid = (low + high) / 2;
		if (v[mid] == target) return mid;
		else if (v[mid] > target) high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}
int main() {
	FAST;
	int n, m;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) cin >> vec[i];
	sort(vec.begin(), vec.end());
	cin >> m;
	vector<int> search(m);
	vector<int> anw(m, 0);
	for (int i = 0; i < m; i++) {
		cin >> search[i];
		if (BSearch(vec, search[i]) != -1) anw[i] = 1;
	}
	for (int i = 0; i < m; i++) cout << anw[i] << "\n";

	return 0;
}