#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int n, i;
	int count[26] = { 0, };//a=97, z=122
	char name[30] = {'\0', };
	char result = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> name;
		count[name[0] - 97]++;
		name[0] = '\0';
	}
	for (i = 0; i < 26; i++) {
		if (count[i] >= 5) {
			result = i + 97;
			cout << result;
		}
	}
	if (result == 0)
		cout << "PREDAJA";
	return 0;
}