// 문자열 인터리빙(Interleaving)
// [Reference]https://velog.io/@embeddedjune/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%B0%B1%EC%A4%80-DP-9177-%EB%8B%A8%EC%96%B4-%EC%84%9E%EA%B8%B0
#include <bits/stdc++.h>
using namespace std;

int n, cnt = 1;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	while (n--) {
		string a, b, c;
		cin >> a >> b >> c;
		int lLen = a.length();
		int rLen = b.length();
		vector<vector<bool>> check(lLen + 1, vector<bool>(rLen + 1));
		check[0][0] = 1;
		for (int i = 1; i <= rLen; i++) check[0][i] = (b[i - 1] == c[i - 1] ? check[0][i - 1] : 0);
		for (int i = 1; i <= lLen; i++) check[i][0] = (a[i - 1] == c[i - 1] ? check[i - 1][0] : 0);
		for (int i = 1; i <= lLen; i++) {
			for (int j = 1; j <= rLen; j++) {
				char A = a[i - 1], B = b[j - 1], C = c[i + j - 1];
				if (A != C && B != C) check[i][j] = 0;
				else if (A != C && B == C) check[i][j] = check[i][j - 1];
				else if (A == C && B != C) check[i][j] = check[i - 1][j];
				else check[i][j] = check[i - 1][j] || check[i][j - 1];
			}
		}
		cout << "Data set " << cnt++ << ": ";
		cout << (check[lLen][rLen] ? "yes" : "no") << '\n';
	}
}