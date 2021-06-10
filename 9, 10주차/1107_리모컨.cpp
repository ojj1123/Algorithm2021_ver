#include <bits/stdc++.h>
using namespace std;

string str;
int n, m, ans;
bool check[10];
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> str >> m;
	n = stoi(str);
	ans = abs(n - 100);
	for (int i = 0; i < m; i++) {
		int tmp; cin >> tmp;
		check[tmp] = 1;
	}
	for (int i = 0; i <= 1000000; i++) {
		string tmp = to_string(i);
		bool flag = 1;
		int len = tmp.length();
		for (int j = 0; j < len; j++) {
			if (check[tmp[j]-'0']) {
				flag = 0;
				break;
			}
		}
		if (flag) ans = min(ans, abs(n - i)+len);
	}
	cout << ans;
}