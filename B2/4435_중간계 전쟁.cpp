#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int t, i, j;
	cin >> t;
	for (i = 0; i < t; i++) {
		int sumG = 0, sumS = 0;
		int G[6], S[7];
		for (j = 0; j < 6; j++)
			cin >> G[j];
		for (j = 0; j < 7; j++)
			cin >> S[j];
		sumG = 1 * G[0] + 2 * G[1] + 3 * G[2] + 3 * G[3] + 4 * G[4] + 10 * G[5];
		sumS = 1 * S[0] + 2 * S[1] + 2 * S[2] + 2 * S[3] + 3 * S[4] + 5 * S[5] + 10 * S[6];
		cout << "Battle " << i + 1 << ": ";
		if (sumG > sumS)
			cout << "Good triumphs over Evil" << "\n";
		else if (sumG == sumS)
			cout << "No victor on this battle field" << "\n";
		else
			cout << "Evil eradicates all trace of Good" << "\n";
	}
	return 0;
}