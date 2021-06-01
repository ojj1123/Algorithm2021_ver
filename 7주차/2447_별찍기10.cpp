#include <bits/stdc++.h>
using namespace std;

char arr[6600][6600];
int n;
void func(int k, int r, int c) {
	if (k == 3) {
		for (int i = c; i < c + 3; i++) arr[r][i] = '*';
		arr[r + 1][c] = arr[r + 1][c + 2] = '*';
		for (int i = c; i < c + 3; i++) arr[r + 2][i] = '*';
		return;
	}
	func(k / 3, r, c);
	func(k / 3, r, c + k / 3);
	func(k / 3, r, c + 2 * k / 3);
	func(k / 3, r + k / 3, c);
	func(k / 3, r + k / 3, c + 2 * k / 3);
	func(k / 3, r + 2 * k / 3, c);
	func(k / 3, r + 2 * k / 3, c + k / 3);
	func(k / 3, r + 2 * k / 3, c + 2 * k / 3);

}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) fill(arr[i], arr[i] + n + 5, ' ');
	func(n, 1, 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cout << arr[i][j];
		cout << '\n';
	}
}