#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	string n;
	int i;
	while (1) {
		cin >> n;
		int len = n.length();
		int centerIndex = len / 2;
		int flag = 1;
		for (i = 0; i < centerIndex; i++) {
			if (n[i] != n[len - 1 - i]) {
				flag = 0;
				break;
			}
		}
		if (n.compare("0") == 0) break;
		if (!flag) cout << "no\n";
		else cout << "yes\n";
	}
	return 0;
}