#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int n, cnt = 99;
	cin >> n;
	if (n < 100) cout << n;
	else {
		for (int i = 100; i <= n; i++) {
			string temp = to_string(i);
			int d = temp[0] - temp[1], flag = 0;
			for (int j = 2; j < temp.length(); j++) {
				if (d != temp[j - 1] - temp[j]) {
					flag = 1;
					break;
				}
			}
			if (!flag) cnt++;
		}
		cout << cnt;
	}
	//sort(arr.begin(), arr.end());//O(nlogn)

	return 0;
}