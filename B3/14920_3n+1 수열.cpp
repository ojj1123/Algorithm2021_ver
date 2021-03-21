#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int c, i;
	cin >> c;
	for (i = 2; c != 1; i++) {
		if (c % 2 == 0) {
			c = c / 2;
		}
		else {
			c = 3 * c + 1;
		}
	}
	cout << i - 1;
	return 0;
}