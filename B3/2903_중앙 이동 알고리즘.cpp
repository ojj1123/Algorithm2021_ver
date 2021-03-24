#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int n, k = 3;
	cin >> n;
	if (n == 1) {
		cout << k * k;
	}
	else {
		while (n != 1) {
			k = 2 * k - 1;
			n--;
		}
		cout << k * k;
	}
	return 0;
}