#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main() {
	FAST;
	string str;
	int m;
	list<char> li;
	cin >> str >> m;
	for (int i = 0; i < str.length(); i++) {
		li.push_back(str[i]);
	}
	auto cursor = li.end();
	while (m--) {
		char command, ch;
		cin >> command;
		if (command == 'L') {
			if (cursor != li.begin()) cursor--;
		}
		else if (command == 'D') {
			if (cursor != li.end()) cursor++;
		}
		else if (command == 'B') {
			if (cursor != li.begin()) {
				cursor--;
				cursor = li.erase(cursor);
			}
		}
		else if (command == 'P') {
			cin >> ch;
			li.insert(cursor, ch);
		}
	}
	for (auto &it : li) {
		cout << it;
	}
	return 0;
}