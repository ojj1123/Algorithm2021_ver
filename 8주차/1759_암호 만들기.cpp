/*
- 처음 시간초과가 난 이유
모든 순열을 다 구하고 거기서 오름차순인지, 모음1개 자음2개 이상이 들어가 있는지 따줘줌
- 해결 방법
애초에 오름차순인 순열을 구함과 동시에 모음, 자음의 개수를 따져줌.(N과M(2) 문제와 유사)
*/
#include <bits/stdc++.h>
using namespace std;
char arr[16];
char res[16];
bool isused[16];
int l, c, mo, ja;
void solve(int k, int num, int a, int b) {
	if (k == l) {
		if (a >= 1 && b >= 2) {
			for (int i = 0; i < l; i++) cout << res[i];
			cout << '\n';
		}
		return;
	}
	for (int i = num; i < c; i++) {
		if (!isused[i]) {
			isused[i] = 1;
			res[k] = arr[i];
			char temp = res[k];
			if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u') mo++;
			else ja++;
			solve(k + 1, i+1, mo, ja);
			if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u') mo--;
			else ja--;
			isused[i] = 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> l >> c;
	for (int i = 0; i < c; i++) cin >> arr[i];
	sort(arr, arr + c);
	solve(0, 0, 0, 0);
}