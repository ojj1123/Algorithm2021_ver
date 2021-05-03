#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int cnt[1001];
int main() {
	FAST;
	int n;
	cin >> n;
	vector <int> a(n), p(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	int res = 0;
	for (int i = 1; i < 1001; i++) {
		if (cnt[i]) {
			for (int j = 0; j < n; j++) {
				if (a[j] == i) {
					p[j] = res++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) cout << p[i] << " ";
	return 0;
}