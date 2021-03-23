#include <string>
#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int time = 0;
	string str;
	char alpha[][5] =
	{
		{'A', 'B', 'C'},
		{'D', 'E', 'F'},
		{'G','H','I'},
		{'J','K','L'},
		{'M','N','O'},
		{'P','Q','R','S'},
		{'T','U','V'},
		{'W','X','Y','Z'},
	};
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < sizeof(alpha) / (sizeof(char) * 5); j++) {
			for (int k = 0; alpha[j][k] != NULL; k++) {
				if (str[i] == alpha[j][k]) time += (j + 3);
			}
		}
	}
	cout << time;
	return 0;
}