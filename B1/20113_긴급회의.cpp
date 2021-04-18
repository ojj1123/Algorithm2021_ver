#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef pair<int, int> P;
bool sortBySecond(const P &a, const P &b) {
	return (a.second > b.second);
}
int main()
{
	FAST;
	int n, i;
	cin >> n;
	vector<P> pArr(n, make_pair(0, 0));
	for (i = 0; i < n; i++)
		pArr[i].first = i + 1;
	
	for (i = 0; i < n; i++) {
		int playNum;
		cin >> playNum;
		if (playNum == 0) continue;
		pArr[playNum - 1].second++;
	}
	sort(pArr.begin(), pArr.end(), sortBySecond);
	if (pArr[0].second != pArr[1].second)
		cout << pArr[0].first;
	else
		cout << "skipped";

	return 0;
}