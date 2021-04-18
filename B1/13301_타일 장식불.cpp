#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int n, i;
	long long a[80];
	cin >> n;
	a[0] = 1;
	a[1] = 1;
	for (i = 2; i < n; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}
	if (n == 1)	cout << 4;
	else cout << 4 * a[n - 1] + 2 * a[n - 2];
	return 0;

}