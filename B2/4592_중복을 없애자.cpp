#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int n, i;
	while (1) {
		cin >> n;
		if (n == 0) break;
		vector<int> tempVec(n);
		for (i = 0; i < n; i++)
			cin >> tempVec[i];
		int tempNum = tempVec[0];
		for (i = 1; i < n; i++) {
			if (tempVec[i] == tempNum)
				tempVec[i] = -1;
			else
				tempNum = tempVec[i];
		}
		for (i = 0; i < n; i++) {
			if (tempVec[i] > 0)
				cout << tempVec[i] << " ";
		}
		cout << "$\n";
	}
	return 0;
}