#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main() {
	FAST;
	int t;
	cin >> t;
	while (t--) {
		string str1, str2;
		cin >> str1 >> str2;
		int len1 = str1.length();
		int len2 = str2.length();
		int carry = 0;
		vector<int> a(85, 0), b(85, 0), sum(85, 0);
		for (int i = 0; i < len1; i++) {
			char temp = str1[i];
			a[len1 - 1 - i] = atoi(&temp);
		}
		for (int i = 0; i < len2; i++) {
			char temp = str2[i];
			b[len2 - 1 - i] = atoi(&temp);
		}
		for (int i = 0; i < max(len1, len2); i++) {
			sum[i] = a[i] + b[i] + carry;
			carry = sum[i] / 2;
			sum[i] = sum[i] % 2;
		}
		if (carry) {
			cout << 1;
			for (int i = 0; i < max(len1, len2); i++) {
				cout << sum[max(len1, len2) - 1 - i];
			}
		}
		else {
			bool flag = false;
			if(!sum[max(len1, len2)-1]) {
				for (int i = 1; i<max(len1, len2); i++) {
					if (!flag&&sum[max(len1, len2) - 1 - i]) {
						flag = true;
					}
					if (flag) {
						cout << sum[max(len1, len2) - 1 - i];
					}
				}
				if (!flag) cout << 0;
			}
			else {
				for (int i = 0; i < max(len1, len2); i++) {
					cout << sum[max(len1, len2) - 1 - i];
				}
			}
		}
		cout << "\n";
	}
	return 0;
}