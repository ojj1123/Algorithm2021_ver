#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int i, n, count = 0;
	cin >> n;
	int *student = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		cin >> student[i];
		if (student[i] != i + 1)
			count++;
	}
	cout << count;
	return 0;
}