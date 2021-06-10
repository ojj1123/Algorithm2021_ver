#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int a, t, anw, result;
	cin >> a >> t >> anw;
	int n = 1;
	while (1) {
		int temp = (n + 7)*n / 2;
		if (temp >= t) {
			break;
		}
		n++;
	}
	int cnt;
	int total = n * (n + 7);
	int temp = total / 2;
	if (anw == 0) {
		cnt = total - (2 * ((total / 2) - t) + 1);
		if (temp - n <= t && t <= temp) {
			cnt = total - ((n + 1) + (temp - t));
		}
	}
	else {
		cnt = total - (2 * ((total / 2) - t));
		if (temp - n <= t && t <= temp) {
			cnt = total - (temp - t);
		}
	}
	result = cnt%a - 1;
	if (result < 0) {
		result = a + result;
	}
	cout << result;
	return 0;
}