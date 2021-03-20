#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int p[4];
	int x, y, r, flag = 1;;
	for (int i = 0; i < 4; i++)
		cin >> p[i];
	cin >> x >> y >> r;
	for (int i = 0; i < 4; i++) {
		if (p[i] == x) {
			cout << i + 1;
			flag = 0;
			break;
		}
	}
	if (flag)
		cout << 0;
	return 0;
}