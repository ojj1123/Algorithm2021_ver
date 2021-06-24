#include <bits/stdc++.h>
using namespace std;

int ans, temp;
string str1, str2;
int lcs[1002][1002];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> str1 >> str2;
	for (int i = 0; i <= str1.size(); i++) {
		for (int j = 0; j <= str2.size(); j++) {
			if (i == 0 || j == 0) lcs[i][j] = 0;
			else if (str1[i - 1] == str2[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			ans = max(ans, lcs[i][j]);
		}
	}
	cout << ans;
}