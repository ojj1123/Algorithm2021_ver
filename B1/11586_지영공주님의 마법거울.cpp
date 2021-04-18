#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int n, k, i, j;
	cin >> n;
	vector<string> m(n);
	for (i = 0; i < n; i++)
		cin >> m[i];
	cin >> k;
	if (k == 1) {
		for (i = 0; i < n; i++) {
			cout << m[i] << "\n";
		}
	}
	else if (k == 2) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < m[i].length(); j++) {
				cout << m[i][m[i].length() - 1 - j];
			}
			cout << "\n";
		}
	}
	else {
		for (i = 0; i < n; i++) {
			cout << m[n - 1 - i] << "\n";
		}
	}
	return 0;
}