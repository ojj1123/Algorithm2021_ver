#include <iostream>
#include <string>
using namespace std;

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main() {
	FAST;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		cout << s[i];
		if ((i + 1) % 10 == 0)
			cout << "\n";
	}
	return 0;
}