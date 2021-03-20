#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int n, k;
	cin >> n;
	k = (n - 5) / 4;
	if (n < 6)
		cout << n;
	else
		cout << ((k % 2 == 0) ? 5 - (n - (5 + 4 * k)) : 1 + (n - (5 + 4 * k)));
	return 0;
}