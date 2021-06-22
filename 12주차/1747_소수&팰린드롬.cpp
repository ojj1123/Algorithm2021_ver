#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	if (n == 1) {
		cout << 2;
		return 0;
	}
	while (1) {
		bool flag = true;
		string tmp = to_string(n);
		reverse(tmp.begin(), tmp.end());
		int temp = stoi(tmp);
		if (temp == n) {
			for (int i = 2; i <= sqrt(n); i++) {
				if (n % i == 0) {
					flag = false;
					break;
				}
			}
			if (flag) {
				cout << n;
				return 0;
			}
		}
 		n++;
	}
}