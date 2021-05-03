#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main() {
	FAST;
	int t, cnt = 0;
	cin >> t;
	while (t--) {
		stack<char> st;
		string str;
		cin >> str;
		int len = str.length();
		for (int i = 0; i < len; i++) {
			if (str[i] == 'A') {
				if (st.empty())
					st.push(str[i]);
				else {
					if (st.top() == 'A') st.pop();
					else if (st.top() == 'B') st.push(str[i]);
				}
			}
			else if (str[i] == 'B') {
				if (st.empty())
					st.push(str[i]);
				else {
					if (st.top() == 'B') st.pop();
					else if (st.top() == 'A') st.push(str[i]);
				}
			}
		}
		if (st.empty()) cnt++;
	}
	cout << cnt;
	return 0;
}