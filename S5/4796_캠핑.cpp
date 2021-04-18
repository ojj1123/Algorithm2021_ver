#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	int L, P, V, result, cnt = 1;
	while (1) {
		result = 0;
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) break;
		while (V != 0) {
			if (V < P) {
				if (V <= L) result += V;
				else result += L;
				V = 0;
			}
			else {
				result += L;
				V -= P;
			}
		}
		cout << "Case " << cnt << ": " << result << "\n";
		cnt++;
	}
	return 0;
}