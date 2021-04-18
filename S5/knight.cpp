#include <string.h>
#include <cmath>
#include <cstring>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;
#pragma warning(disable:4996)
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	string knight[36];
	bool check[6][6] = { false, };
	int before_x, before_y, i;
	for (i = 0; i < 36; i++)
		cin >> knight[i];
	for (i = 0; i < 36; i++) {
		int x = knight[i][0] - 'A', y = knight[i][1] - '1';
		bool temp = check[x][y];
		if (i == 0) {
			temp = true;
		}
		else {
			if (!temp) {//temp==flase
				int abs_x = abs(before_x - x), abs_y = abs(before_y - y);
				if (!((abs_x == 2 && abs_y == 1) || (abs_x == 1 && abs_y == 2))) {//경로 이탈함
					break;
				}
				else temp = true;//경로 맞아 그렇니까 지난거로 표시해줘
			}
			else break;//temp==true
		}//논리 수정
		before_x = knight[i][0] - 'A', before_y = knight[i][1] - '1';
	}
	if (i != 36) cout << "Invalid";
	else {
		int abs_x = abs(knight[0][0] - knight[35][0]), abs_y = abs(knight[0][1] - knight[35][1]);
		if((abs_x==2&&abs_y==1)||(abs_x==1&&abs_y==2)) cout << "Valid";
		else cout << "Invalid";
	}
	return 0;
}