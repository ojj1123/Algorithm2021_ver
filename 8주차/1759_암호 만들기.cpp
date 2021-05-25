/*
- ó�� �ð��ʰ��� �� ����
��� ������ �� ���ϰ� �ű⼭ ������������, ����1�� ����2�� �̻��� �� �ִ��� ������
- �ذ� ���
���ʿ� ���������� ������ ���԰� ���ÿ� ����, ������ ������ ������.(N��M(2) ������ ����)
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