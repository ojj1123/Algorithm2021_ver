#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main() {
	FAST;
	long long k, n, len, max_ = -1;
	cin >> k >> n;
	vector<long long> arr(k);
	for (long long i = 0; i < k; i++) {
		cin >> len;//랜선 길이들 배열
		arr[i] = len;
		if (len > max_) max_ = len;
	}
	long long start = 1, end = max_, mid, res = 0, tempSum;
	while (start < end) {
		mid = (start + end) / 2;
		tempSum = 0;
		for (int i = 0; i < k; i++)
			tempSum += arr[i] / mid;
		if (n > tempSum) end = mid - 1;
		else if (n < tempSum) {
			start = mid + 1;
			res = max(res, mid);
		}
		else {
			res = max(res, mid);
			break;
		}
	}
	for (long long i = end; i >= res; i--) {
		tempSum = 0;
		for (int j = 0; j < k; j++)
			tempSum += arr[j] / i;
		if (n <= tempSum) {
			res = i;
			break;
		}
	}
	cout << res;
	return 0;
}
//오버플로우