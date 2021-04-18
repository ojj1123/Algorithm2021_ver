#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define N 100

int score[N];

int main() {
	FAST;
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> score[i];
	for (int i = n - 1; i > 0; i--) {
		if (score[i] <= score[i - 1]) {
			int temp = score[i - 1] - score[i] + 1;
			score[i - 1] -= temp;
			cnt += temp;
		}
	}
	cout << cnt;
	return 0;
}