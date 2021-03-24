#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int a, d, k, n;
	double fN;
	cin >> a >> d >> k;
	n = ((k - a) / d) + 1;
	fN = ((k - a) / ((double)d)) + 1;
	if (fN - n != 0 || n==0) cout << "X";
	else cout << n;
	return 0;
}