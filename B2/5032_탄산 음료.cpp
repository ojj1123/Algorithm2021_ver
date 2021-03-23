#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int e, f, c, sum = 0;
	cin >> e >> f >> c;
	e = e + f;
	while (1) {
		sum = sum + (e / c);
		e = e % c + e / c;
		if (e < c) break;
	}
	cout << sum;

	return 0;
}