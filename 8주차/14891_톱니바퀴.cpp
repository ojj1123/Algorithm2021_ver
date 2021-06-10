#include <bits/stdc++.h>
using namespace std;

string wheel;
deque<char> deq[4];
int k; // 회전 횟수
void rotation(deque<char>& d, int mode) {
	if (mode == 1) {
		char tmp = d.back();
		d.pop_back();
		d.push_front(tmp);
	}
	else {
		char tmp = d.front();
		d.pop_front();
		d.push_back(tmp);
	}
}
int main(void) {
	for (int i = 0; i < 4; i++) {
		cin >> wheel;
		for (int j = 0; j < 8; j++) deq[i].push_back(wheel[j]);
	}
	cin >> k;
	while (k--) {
		bool check[3] = { 0, }; // 1-2 : 0 / 2-3 : 1 / 3-4 : 2 사이사이 다르면 1 같으면 0
		int num, dir; // 톱니바퀴의 index : num-1
		cin >> num >> dir;
		vector<int> rotate(4, dir);
		for (int i = 0; i < 3; i++) {
			if (deq[i][2] != deq[i + 1][6]) { // 다르면
				check[i] = 1; // 돌릴 수 있음
			}
		}// 다른지 같은지
		if (num % 2 == 0) {
			for (int i = 0; i < 4; i++)
				if ((i + 1) % 2 == 1) rotate[i] = dir > 0 ? -1 : 1;
		}
		else {
			for (int i = 0; i < 4; i++)
				if ((i + 1) % 2 == 0) rotate[i] = dir > 0 ? -1 : 1;
		}// 다 돈다면 회전방향 저장
		rotation(deq[num - 1], dir);
		if (num == 1) {
			for (int i = 0; i < 3; i++) {
				if (check[i]) rotation(deq[i + 1], rotate[i + 1]);
				else break;
			}
		}
		else if (num == 2) {
			if (check[0]) rotation(deq[0], rotate[0]);
			if (check[1]) {
				rotation(deq[2], rotate[2]);
				if (check[2]) rotation(deq[3], rotate[3]);
			}
		}
		else if (num == 3) {
			if (check[2]) rotation(deq[3], rotate[3]);
			if (check[1]) {
				rotation(deq[1], rotate[1]);
				if (check[0]) rotation(deq[0], rotate[0]);
			}
		}
		else {
			for (int i = 2; i >= 0; i--) {
				if (check[i]) rotation(deq[i], rotate[i]);
				else break;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (deq[i][0] == '1') ans += pow(2, i);
	}
	cout << ans;
}