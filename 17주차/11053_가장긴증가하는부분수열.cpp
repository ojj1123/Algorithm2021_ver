// 복습
// O(NlogN) - lower_bound 이용
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, lis_size;
int arr[1002];
int lis[1002];
void init()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}
void solve()
{
	lis[0] = arr[0];
	lis_size = 1;
	for (int i = 1; i < n; i++)
	{
		if (lis[lis_size - 1] < arr[i])
		{
			lis[lis_size] = arr[i];
			lis_size++;
		}
		else
		{
			int idx = lower_bound(lis, lis + lis_size, arr[i]) - lis;
			lis[idx] = arr[i];
		}
	}
}
int main()
{
	init();
	solve();
	cout << lis_size << endl;
	return 0;
}