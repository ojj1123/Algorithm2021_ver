#include <iostream>
using namespace std;
int main()
{
	int L, t = 0, v = 5;
	cin >> L;
	while (1) {
		if (L == 0)
			break;
		else {
			if (L / v == 0) {
				v--;
			}
			else {
				t += L / v;
				L %= v;
			}
		}
	}
	cout << t;
	return 0;
}