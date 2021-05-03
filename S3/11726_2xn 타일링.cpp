#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int fibo[1005];
int main() {
	FAST;
	int n;
	cin >> n;
	fibo[0] = 1;
	fibo[1] = 1;
	for (int i = 2; i <= n; i++) {
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 10007;
	}
	cout << fibo[n];
	return 0;
}