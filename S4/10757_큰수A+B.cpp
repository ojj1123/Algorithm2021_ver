#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int a[10004], b[10004], sum[10004], carry;
string str1, str2;
int main() {
	FAST;
	cin >> str1 >> str2;
	for (int i = 0; i < str1.length(); i++) {
		char temp = str1.at(i);
		a[str1.length()- i] = atoi(&temp);
	}
	for (int i = 0; i < str2.length(); i++) {
		char temp = str2.at(i);
		b[str2.length() - i] = atoi(&temp);
	}
	for (int i = 1; i <= max(str1.length(), str2.length()); i++) {
		sum[i] = a[i] + b[i] + carry;
		if (sum[i] >= 10) {
			sum[i] -= 10;
			carry = 1;
		}
		else carry = 0;
	}
	if (carry) cout << 1;
	for (int i = 0; i < max(str1.length(), str2.length()); i++) {
		cout << sum[max(str1.length(), str2.length()) - i];
	}

	return 0;
}