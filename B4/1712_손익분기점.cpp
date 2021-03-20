#include <iostream>
using namespace std;

int main()
{
	int A, B, C;
	int num = 1;
	cin >> A >> B >> C;
	if (B >= C) {
		num = -1;
	}
	else {
		int temp = A / (C - B);
		num = temp + 1;
	}
	cout << num;
	return 0;
}