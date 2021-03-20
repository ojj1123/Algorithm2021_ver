#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int n, i, j, space;
	cin >> n;
	for (i = 1; i < n + 1; i++) {
		space = 2 * (n - i);
		for (j = 0; j < i; j++) {
			cout << "*";
		}
		for (j = 0; j < space; j++) {
			cout << " ";
		}
		for (j = 0; j < i; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	for (i = 1; i < n; i++) {
		space = 2 * i;
		for (j = i; j < n; j++) {
			cout << "*";
		}
		for (j = 0; j < space; j++) {
			cout << " ";
		}
		for (j = i; j < n; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}