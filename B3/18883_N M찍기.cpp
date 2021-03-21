#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int i, j, n, m;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << i * m + (j + 1);
			if (j != m - 1)
				cout << " ";
		}
		cout << "\n";
	}
	return 0;
}