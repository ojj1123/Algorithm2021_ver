#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main() {
	FAST;
	string str;
	int t;
	cin >> t;
	while (t--) {
		cin >> str;
		stack<char> st;
		int len = str.length();
		bool flag = true;
		for (int i = 0; i < len; i++) {
			if (str[i] == '(')
				st.push(str[i]);
			else if (str[i] == ')') {
				if (!st.empty())
					st.pop();
				else
					flag = false;
			}
		}
		if (flag) {
			if (!st.empty()) cout << "NO\n";
			else cout << "YES\n";
		}
		else cout << "NO\n";
	}
	return 0;
}