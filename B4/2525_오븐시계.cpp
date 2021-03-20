#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	int h, m;
	cin >> a >> b;
	cin >> c;
	h = c / 60;
	a += h;
	c %= 60;
	m = c;
	b += m;
	if (b >= 60) {
		a += b / 60;
		b %= 60;
	}
	if (a > 23) {
		a -= 24;
	}
	cout << a << " " << b;
	return 0;
}