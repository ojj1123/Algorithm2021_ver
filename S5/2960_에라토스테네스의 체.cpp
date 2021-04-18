#include <cmath>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;
#pragma warning(disable:4996)
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int n, k, i, j, cnt = 0;
	cin >> n >> k;
	vector<P> prime(n + 1, make_pair(1, 1));
	int result, flag = 0;

	for (i = 2; i <= sqrt((double)n); i++) {
		if (prime[i].first == 0) continue;
		else {
			for (j = i * i; j <= n; j += i) {
				prime[j].first = 0;
			}
		}
	}
	for (i = 2; i <= n; i++) {
		if (prime[i].first) {
			if (prime[i].second) {
				prime[i].second = 0;
				cnt++;
				if (cnt == k) {
					result = i;
					break;
				}
			}
			else continue;
		}
		for (j = i * i; j <= n; j += i) {
			if (prime[j].second) {
				prime[j].second = 0;
				cnt++;
				if (cnt == k) {
					flag = 1;
					result = j;
					break;
				}
			}
			else continue;
		}
		if (flag) break;
	}
	cout << result;
	return 0;
}