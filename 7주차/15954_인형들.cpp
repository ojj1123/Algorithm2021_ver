// 조건을 잘 확인해야 하는 문제
#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

long double avg(long double sum, long double cnt) {
	return sum / cnt;
}
long double sd(vector<long double> &v, long double m, long double k, int start, int end) {
	long double tempSum = 0;
	for (int i = start; i < end; i++)
		tempSum += ((v[i] - m)*(v[i] - m));
	return sqrt(tempSum / k);
}
int main() {
	FAST;
	long double n, k;
	cin >> n >> k;
	vector<long double> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int start = 0, end = k-1;
	long double sum = 0, m, sd_val = 1000000, tempSum = 0;
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = i; j < n; j++) {
			if (j < k + i) {
				sum += a[j];
				if (j == k + i - 1) {
					m = avg(sum, k);
					sd_val = min(sd_val, sd(a, m, k, i, k+i));
				}
			}
			else {
				sum += a[j];
				m = avg(sum, j - i + 1);
				sd_val = min(sd_val, sd(a, m, j - i + 1, i, j + 1));

			}
		}

	}
	//cout << fixed;
	cout.precision(20);
	cout << sd_val;
	return 0;
}