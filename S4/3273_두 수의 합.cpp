#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define N 1000001

int main() {
	FAST;
	int n, x, num = 0;
	bool cnt[N] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		cnt[temp] = true;
	}
	cin >> x;
	for (int i = 1; i < N; i++) {
		if (cnt[i]) {
			int temp = x - i;
			if (i >= temp) break;
			else if (cnt[temp]) num++;
		}
	}
	cout << num;
	return 0;
}