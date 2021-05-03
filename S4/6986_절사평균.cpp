#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main() {
	FAST;
	int n, k;
	double a1, a2;
	cin >> n >> k;
	cout << fixed;
	cout.precision(2);
	vector<double> s(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	sort(s.begin(), s.end());
	double sum = 0;
	for (int i = k; i < n - k; i++)
		sum += s[i];
	a1 = sum / (n - 2 * k);
	a1 = round(a1 * 100) / (double)100;
	double first = s[k], last = s[n - k - 1];
	sum = 0;
	for (int i = 0; i < n; i++) {
		if (i < k) sum += first;
		else if (i >= n - k) sum += last;
		else sum += s[i];
	}
	a2 = sum / n;
	a2 = round(a2 * 100) / (double)100;
	cout << a1 << "\n" << a2;
	return 0;
}