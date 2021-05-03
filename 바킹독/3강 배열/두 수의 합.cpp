#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int arr[1000];
int cnt[101];
int func2(int arr[], int len) {
	for (int i = 0; i < len; i++) cnt[arr[i]]++;
	for (int i = 0; i < len; i++) {
		int temp = 100 - arr[i];
		if (cnt[temp]) return 1;
	}
	return 0;
}
int main() {
	FAST;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	cout << func2(arr, n);
	return 0;
}