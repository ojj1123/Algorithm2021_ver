#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int i, j, t;
	cin >> t;
	for (i = 0; i < t; i++) {
		int n;
		cin >> n;
		int maxK = 0;
		int minK = 99;
		for (j = 0; j < n; j++) {
			int k;
			cin >> k;
			if (maxK <= k) maxK = k;
			if (minK >= k) minK = k;
		}
		cout << (maxK - minK) * 2 << "\n";
	}
	return 0;
}