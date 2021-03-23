#include <vector>
#include <string>
#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int t, i, j;
	cin >> t;
	for (i = 0; i < t; i++) {
		string str1, str2;
		cin >> str1 >> str2;
		cout << "Distances: ";
		for (j = 0; j < str1.length(); j++) {
			int output;
			if (str2[j] >= str1[j]) output = str2[j] - str1[j];
			else output = (str2[j] + 26) - str1[j];
			cout << output << " ";
		}
		cout << "\n";
	}
	return 0;
}