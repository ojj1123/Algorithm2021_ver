#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main() {
	FAST;
	string n;
	int cnt[10] = { 0, };
	cin >> n;
	for (int i = 0; i < n.length(); i++) 
		cnt[n[i] - '0']++;
	int total_6_9 = cnt[6] + cnt[9];
	if (total_6_9 % 2 == 0) total_6_9 /= 2;
	else total_6_9 = total_6_9 / 2 + 1;
	int max = -1;
	for (int i = 0; i < 10; i++) {
		if (i != 6 && i != 9) {
			max = max < cnt[i] ? cnt[i] : max;
		}
	}
	cout << (max > total_6_9 ? max : total_6_9);
	return 0;
}