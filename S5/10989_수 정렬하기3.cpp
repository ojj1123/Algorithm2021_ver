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
	int n, i, j, temp, maxNum = 0;
	cin >> n;
	vector<int> countArr(10001, 0);
	for (i = 0; i < n; i++) {
		cin >> temp;
		if (maxNum < temp) maxNum = temp;
		countArr[temp]++;
	}
	countArr.resize(maxNum + 1);
	for (i = 1; i < countArr.size(); i++)
		countArr[i] += countArr[i - 1];
	for (i = 1; i < countArr.size(); i++) {
		for (j = countArr[i - 1]; j < countArr[i]; j++) {
			cout << i << "\n";
		}
	}
	return 0;
}