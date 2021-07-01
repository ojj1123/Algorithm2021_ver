#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll arr[5002], a, b, c;
ll temp, Min = 3*10e9 + 2;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n - 2; i++) {
		int j, k;
		j = i + 1; k = n - 1;
		while (j < k) {
			temp = arr[i] + arr[j] + arr[k];
			ll nx = temp < 0 ? -temp : temp;
			if (Min > nx) {
				Min = nx;
				a = arr[i];
				b = arr[j];
				c = arr[k];
			}
			if (temp > 0) k--;
			else j++;
		}
	}
	cout << a << ' ' << b << ' ' << c;
}