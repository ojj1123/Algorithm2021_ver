#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning(disable:4996)
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	vector<pair<string, bool>> total(504, make_pair("", true));
	char i, j, k;
	int idx = 0;
	for (i = '1'; i <= '9'; i++) {
		for (j = '1'; j <= '9'; j++) {
			if (j == i) continue;
			for (k = '1'; k <= '9'; k++) {
				if (k == i || k == j) continue;
				total[idx].first.append(1, i);
				total[idx].first.append(1, j);
				total[idx].first.append(1, k);
				idx++;
			}
		}
	}
	int n, total_cnt = 0;
	cin >> n;
	while (n != 0) {
		string num;
		int strike, ball;
		cin >> num >> strike >> ball;
		for (auto &it : total) {
			int strike_cnt = 0, ball_cnt = 0;
			for (j = 0; j < 3; j++) {
				for (k = 0; k < 3; k++) {
					if (j == k && it.first[j] == num[k])
						strike_cnt++;
					if (j != k && it.first[j] == num[k])
						ball_cnt++;
				}
			}
			if (strike_cnt != strike || ball_cnt != ball)
				it.second = false;
		}
		n--;
	}
	for (auto &iter:total) {
		if (iter.second) total_cnt++;
	}
	cout << total_cnt;
	return 0;
}