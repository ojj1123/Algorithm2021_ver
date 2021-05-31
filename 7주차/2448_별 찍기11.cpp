#include <bits/stdc++.h>
using namespace std;

char arr[3100][6200];

void func(int num, int r, int c) {
	if (num == 3) {
		arr[r][c] = '*';
		arr[r + 1][c - 1] = arr[r + 1][c + 1] = '*';
		for (int i = c - 2; i <= c + 2; i++)
			arr[r + 2][i] = '*';
		return;
	}
	func(num / 2, r + num/2, c - num/2);
	func(num / 2, r, c);
	func(num / 2, r + num/2, c + num/2);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) fill(arr[i], arr[i] + 2 * n, ' ');
	func(n, 1, n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 2 * n - 1; j++) cout << arr[i][j];
		cout << '\n';
	}
}