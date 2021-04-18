#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int i, j;
	char puzzle[4][4];
	char correctPuzzle[4][4];
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			correctPuzzle[i][j] = 'A' + 4 * i + j;
			if (i == 3 && j == 3) correctPuzzle[i][j] = '.';
		}
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			cin >> puzzle[i][j];
		}
	}
	char searchAlpha = 'A';
	int sum = 0, temp_i, temp_j;
	while (1) {
		int flag = 0;
		temp_i = 0, temp_j = 0;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				if (correctPuzzle[i][j] == searchAlpha) {
					temp_i = i, temp_j = j;
					flag = 1;
					break;
				}
				if (flag) break;
			}
		}
		flag = 0;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				if (searchAlpha == puzzle[i][j]) {
					temp_i = abs(temp_i - i);
					temp_j = abs(temp_j - j);
					flag = 1;
					break;
				}
			}
			if (flag) break;
		}
		sum = sum + temp_i + temp_j;
		searchAlpha++;
		if (searchAlpha > 'O') break;
	}
	cout << sum;
	return 0;

}