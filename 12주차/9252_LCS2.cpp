// [Reference] https://velog.io/@emplam27/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EA%B7%B8%EB%A6%BC%EC%9C%BC%EB%A1%9C-%EC%95%8C%EC%95%84%EB%B3%B4%EB%8A%94-LCS-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Longest-Common-Substring%EC%99%80-Longest-Common-Subsequence
#include <bits/stdc++.h>
using namespace std;

int ans, temp;
string str1, str2;
vector<char> str3;
int lcs[1002][1002];
void searchString(int x, int y) {
	if (lcs[x][y] == 0) return;
	if (lcs[x][y] == lcs[x - 1][y]) {
		searchString(x - 1, y);
	}
	else if (lcs[x][y] == lcs[x][y - 1]) {
		searchString(x, y - 1);
	}
	else {
		str3.push_back(str1[x-1]);
		searchString(x - 1, y - 1);
	}
}
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
	searchString(str1.size(), str2.size());
	cout << ans<<'\n';
	for (int i = str3.size()-1; i >= 0; i--) cout << str3[i];
}