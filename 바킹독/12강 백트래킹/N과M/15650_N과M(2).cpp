// Combination
#include <bits/stdc++.h>
using namespace std;
int n, m;
int main(void) {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	vector<int> arr(n), temp(n, 1);
	for (int i = 0; i < n; i++) arr[i] = i + 1;
	for (int i = 0; i < m; i++) temp[i] = 0;
	do {
		for (int i = 0; i < n; i++) {
			if (temp[i] == 0)
				cout << arr[i] << ' ';
		}
		cout << '\n';
	} while (next_permutation(temp.begin(), temp.end()));
}

// #include <bits/stdc++.h>
// using namespace std;
// int n, m;
// int arr[10];
// bool isused[10];
// void solve(int num, int k) {
// 	if (k == m) {
// 		for (int i = 0; i < m; i++) cout << arr[i] << ' ';
// 		cout << '\n';
// 		return;
// 	}
// 	for (int i = num; i <= n; i++) {
// 		if(!isused[i]) {
// 			isused[i] = 1;
// 			arr[k] = i;
// 			solve(i + 1, k + 1);
// 			isused[i] = 0;
// 		}
// 	}
// }
// int main(void) {
// 	ios::sync_with_stdio(0), cin.tie(0);
// 	cin >> n >> m;
// 	solve(1, 0);
// }