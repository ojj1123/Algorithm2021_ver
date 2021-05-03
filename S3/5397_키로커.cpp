#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main() {
	FAST;
	int t;
	cin >> t;
	while (t--) {
		string str;
		list<char> res;
		auto cursor = res.end();
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '<') {
				if (cursor != res.begin()) cursor--;
			}
			else if (str[i] == '>') {
				if (cursor != res.end()) cursor++;
			}
			else if (str[i] == '-') {
				if (cursor != res.begin()) {
					cursor--;
					cursor = res.erase(cursor);
				}
			}
			else res.insert(cursor, str[i]);
		}
		for (auto &it : res) cout << it;
		cout << "\n";
	}
	return 0;
}