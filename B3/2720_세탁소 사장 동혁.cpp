#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int T, i;
	cin >> T;
	for (i = 0; i < T; i++) {
		int c, q, d, n, p;
		cin >> c;
		q = c / 25;
		c %= 25;
		d = c / 10;
		c %= 10;
		n = c / 5;
		c %= 5;
		p = c / 1;
		cout << q << " " << d << " " << n << " " << p << endl;
	}
	
	return 0;
}