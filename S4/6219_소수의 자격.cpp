#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define N 4000005
int a, b;
char d;
bool prime[N];
int main() {
	FAST;
	cin >> a >> b >> d;
	for (int i = 2; i <= sqrt((double)b); i++) {
		if (prime[i]) continue;//false->primeNum
		else {
			for (int j = i * i; j <= b; j += i) {
				prime[j] = true;
			}
		}
	}
	int cnt = 0;
	bool flag;
	for (int i = a; i <= b; i++) {
		if (!prime[i]) {
			string temp = to_string(i);
			flag = false;
			for (int j = 0; j < temp.length(); j++) {
				if (temp[j] == d) {
					flag = true;
					break;
				}
			}
			if (flag) cnt++;
		}
	}
	cout << cnt;
	return 0;
}