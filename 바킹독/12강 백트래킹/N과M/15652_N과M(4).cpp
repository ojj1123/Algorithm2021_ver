//88ms
#include <bits/stdc++.h>
using namespace std;
int arr[10];
int n, m;
void solve(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			if (i < m - 1 && arr[i] > arr[i + 1]) return;
		}
		for (int i = 0; i < m; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		arr[k] = i;
		solve(k + 1);
	}
}
int main(void) {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	solve(0);
}

// 4ms
// #include <bits/stdc++.h>
// using namespace std;
// int arr[10];
// int n, m;
// void solve(int k, int num) {
// 	if (k == m) {
// 		for (int i = 0; i < m; i++) {
// 			if (arr[i]==0) return;
// 		}
// 		for (int i = 0; i < m; i++) cout << arr[i] << ' ';
// 		cout << '\n';
// 		return;
// 	}
// 	for (int i = num-1; i <= n; i++) {
// 		arr[k] = i;
// 		solve(k + 1, i+1);
// 	}
// }
// int main(void) {
// 	ios::sync_with_stdio(0), cin.tie(0);
// 	cin >> n >> m;
// 	solve(0,1);
// }