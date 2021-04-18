#include <iostream>
#include <cmath>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	unsigned int s;
	int n;
	cin >> s;
	n = sqrt((double)s * 2);//¹«½¼ ±Ù°Å·Î?
	while ((n*n) + n > s * 2)
		n--;
	cout << n;
	return 0;
}