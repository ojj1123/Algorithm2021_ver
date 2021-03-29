#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int n, m, i, j, t;
	cin >> n >> m;
	int **arr2d = new int*[n];
	for (i = 0; i < n; i++)
		arr2d[i] = new int[m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> arr2d[i][j];
		}
	}
	cin >> t;
	int x1, x2, y1, y2, loop, sum;
	for (loop = 0; loop < t; loop++) {\
		sum = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		for (i = x1-1; i < x2; i++) {
			for (j = y1 - 1; j < y2; j++) {
				sum += arr2d[i][j];
			}
		}
		cout << sum << "\n";
	}

	for (i = 0; i < n; i++)
		delete[] arr2d[i];
	delete[] arr2d;
	return 0;
}