#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef pair<int, int> P;
bool compare(const P &a, const P &b) {
	return (a.second > b.second);
}
int main()
{
	FAST;
	int n, i, j, k, idx;
	cin >> n;
	vector<vector<int>> vec(n, vector<int>(5, 0));
	vector<P> maxArr(n, make_pair(0, 0));
	for (idx = 0; idx < n; idx++) {
		for (i = 0; i < 5; i++)
			cin >> vec[idx][i];
		int maxNum = 0;
		int tempNum;
		for (i = 0; i < 3; i++) {
			for (j = i + 1; j < 4; j++) {
				for (k = j + 1; k < 5; k++) {
					tempNum = vec[idx][i] + vec[idx][j] + vec[idx][k];
					tempNum -= ((tempNum / 10) * 10);
					if (maxNum < tempNum) maxNum = tempNum;
				}
			}
		}
		maxArr[idx] = make_pair(idx + 1, maxNum);
	}
	int tempMax = maxArr[0].second;
	int resultIdx = 0;
	for (i = 0; i < n; i++) {
		if (tempMax <= maxArr[i].second) {
			tempMax = maxArr[i].second;
			resultIdx = i;
		}
	}
	cout << maxArr[resultIdx].first;
	return 0;
}