#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void swapNum(char &a, char &b) {
	char tmp = a;
	a = b;
	b = tmp;
}
int checkHorizental(char arr[][50], int i, int j, char target, int len) {//수평
	int tempj = j;
	int cnt = 0;
	while (tempj <= len - 1) {
		if (target != arr[i][tempj]) break;
		cnt++, tempj++;
	}
	tempj = j;
	while (tempj - 1 >= 0) {
		if (target != arr[i][tempj - 1]) break;
		cnt++, tempj--;
	}
	return cnt;
}
int checkVertical(char arr[][50], int i, int j, char target, int len) {//수직
	int tempi = i;
	int cnt = 0;
	while (tempi <= len - 1) {
		if (target != arr[tempi][j]) break;
		cnt++, tempi++;
	}
	tempi = i;
	while (tempi - 1 >= 0) {
		if (target != arr[tempi - 1][j]) break;
		cnt++, tempi--;
	}
	return cnt;
}
int main() {
	FAST;
	char a[50][50] = { 0, };
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	int res = 0;
	int cnt1 = 0, cnt2 = 0;
	//수평
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			swapNum(a[i][j], a[i][j + 1]);
			//cout << a[i][j] << a[i][j + 1] << " ";
			int tmpcnt1 = checkHorizental(a, i, j, a[i][j], n);
			int tmpcnt1_ = checkHorizental(a, i, j + 1, a[i][j + 1], n);
			cnt1 = tmpcnt1 > tmpcnt1_ ? tmpcnt1 : tmpcnt1_;
			int tmpcnt2 = checkVertical(a, i, j, a[i][j], n);
			int tmpcnt2_ = checkVertical(a, i, j + 1, a[i][j + 1], n);
			cnt2 = tmpcnt2 > tmpcnt2_ ? tmpcnt2 : tmpcnt2_;
			int tempMax = max(cnt1, cnt2);
			res = max(res, tempMax);
			swapNum(a[i][j], a[i][j + 1]);
			//cout << a[i][j] << a[i][j + 1] << endl;

		}
	}
	//cout << "///////////////////" << endl;
	//수직
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n; j++) {
			swapNum(a[i][j], a[i + 1][j]);
			//cout << a[i][j] << a[i + 1][j] << " ";
			int tmpcnt1 = checkHorizental(a, i, j, a[i][j], n);
			int tmpcnt1_ = checkHorizental(a, i + 1, j, a[i + 1][j], n);
			cnt1 = tmpcnt1 > tmpcnt1_ ? tmpcnt1 : tmpcnt1_;
			int tmpcnt2 = checkVertical(a, i, j, a[i][j], n);
			int tmpcnt2_ = checkVertical(a, i + 1, j, a[i + 1][j], n);
			cnt2 = tmpcnt2 > tmpcnt2_ ? tmpcnt2 : tmpcnt2_;
			int tempMax = max(cnt1, cnt2);
			res = max(res, tempMax);
			swapNum(a[i][j], a[i + 1][j]);
			//cout << a[i][j] << a[i + 1][j] << endl;
		}
	}
	cout << res;
	return 0;
}