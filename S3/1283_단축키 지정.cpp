#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main() {
	FAST;
	int t;
	bool ch[26] = { 0, };
	cin >> t;
	cin.ignore();
	while (t--) {
		string str, temp;
		int idx = 0, res = -1;
		vector<int> first(5, -1);//첫 글자들의 위치
		getline(cin, str);
		temp = str;
		first[0] = idx++;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ') {
				first[idx] = i + 1;
				idx++;//단어의 개수는 idx
			}
			else temp[i] = tolower(str[i]);
		}
		bool flag = false;
		for (int i = 0; i < idx; i++) {
			if (!ch[temp[first[i]] - 'a']) {
				ch[temp[first[i]] - 'a'] = true;
				res = first[i];
				flag = true;
				break;
			}
		}//첫 문자 검사
		if (!flag) {//단어들의 첫 문자가 이미 단축키로 지정되서 나머지에서 함
			for (int i = 0; i < str.length(); i++) {
				if (temp[i]!=' ' && !ch[temp[i] - 'a']) {
					ch[temp[i] - 'a'] = true;
					res = i;
					break;
				}
			}
		}
		for (int i = 0; i < str.length(); i++) {
			if (i == res) cout << "[" << str[i] << "]";
			else cout << str[i];
		}
		cout << "\n";
	}
	return 0;
}