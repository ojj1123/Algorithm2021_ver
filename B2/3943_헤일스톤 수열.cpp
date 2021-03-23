#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
    FAST;
    int T, c, i, j;
    cin >> T;
    for (j = 0; j < T; j++)
    {
        cin >> c;
        int maxC = c;
        for (i = 2; c != 1; i++)
        {
            if (c % 2 == 0)
            {
                c = c / 2;
            }
            else
            {
                c = 3 * c + 1;
            }
            if (maxC < c)
            {
                maxC = c;
            }
        }
        cout << maxC << "\n";
    }
    /*int T, i;
	cin >> T;
	for (i = 0; i < T; i++) {
		int n, vecSize = 2;
		cin >> n;
		vector<int> vec(vecSize, 0);
		vec.push_back(n);
		while (n != 1) {
			if (n % 2 == 0)
				n = n / 2;
			else
				n = 3 * n + 1;
			vec.push_back(n);
			vec.resize(++vecSize);
		}
		cout << *max_element(vec.begin(), vec.end()) << endl;
	}*/
    // time over
    return 0;
}