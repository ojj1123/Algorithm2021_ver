#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main() {
	FAST;
	int idx = 1;
	while (1) {
		string str;
		int cnt = 0;
		cin >> str;
		if (str[0] == '-') break;
		stack<char> st;
		int len = str.length();
		for (int i = 0; i < len; i++) {
			char &temp = str[i];
			if (st.empty() && temp == '}') {
				temp = '{';
				cnt++;
				st.push(temp);
			}
			else if (!st.empty() && temp == '}') st.pop();
			else { // {
				st.push(temp);
			}
		}
		cout << idx++ << ". " << cnt + st.size() / 2 << "\n";
	}
	return 0;
}
// https://peanut2016.tistory.com/63