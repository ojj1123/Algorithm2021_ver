#include <bits/stdc++.h>
using namespace std;
int n, len;
int lis[40005];
int mylower_bound(int arr[], int n, int key) {
	int start = 0;
	int end = n;
	int mid;
	while (end - start > 0) {
		mid = (start + end) / 2;
		if (arr[mid] < key) start = mid + 1;
		else end = mid;
	}
	return end;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	len = 1;
	for (int i = 0; i < n; i++) {
		int here; cin >> here;
		if (i == 0) lis[i] = here;
		else {
			int pos = mylower_bound(lis, len, here);
			lis[pos] = here;
			if (pos == len) len++;
		}
	}
	cout << len;
}