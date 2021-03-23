#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int l, r, a, total, outNum;
	cin >> l >> r >> a;
	total = l + r + a;
	if (l > r) {
		int tempR = r + a;
		outNum = (tempR > l) ? (((tempR - l) % 2 == 0) ? 0 : 1) : (l - tempR);
	}
	else if (l == r) {
		outNum = (a % 2 == 0) ? 0 : 1;
	}
	else {
		int tempL = l + a;
		outNum = (tempL > r) ? (((tempL - r) % 2 == 0) ? 0 : 1) : (r - tempL);
	}
	total -= outNum;
	cout << total;
	return 0;
}