#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int year;
	cin >> year;
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
		cout << "1";
	}
	else {
		cout << "0";
	}
	return 0;
}