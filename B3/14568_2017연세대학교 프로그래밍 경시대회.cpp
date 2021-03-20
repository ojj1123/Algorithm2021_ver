#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int n, tempN, a, b, count = 0;
	cin >> n;
	tempN = n;
	a = 2;
	while (1) {
		n = tempN - a;
		b = 1;
		while (1) {
			if (b <= (n - 2) / 2) {
				count++;
			}
			else
				break;
			b++;
		}
		a += 2;
		if (a >= tempN) {
			break;
		}
	}
	cout << count;
	return 0;
}