#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n, lis_size;
int arr[1002];
int lis[1002];
vector<int> res;
vector<pair<int, int>> ans(1001);
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
	ans[0] = {0, arr[0]}; // { lis에 들어가는 인덱스, arr값 }
	for (int i = 1; i < n; i++)
	{
		int tmp;
		if (lis[lis_size - 1] < arr[i])
		{
			lis[lis_size] = arr[i];
			tmp = lis_size;
			lis_size++;
		}
		else
		{
			int idx = lower_bound(lis, lis + lis_size, arr[i]) - lis;
			tmp = idx;
			lis[idx] = arr[i];
		}
		ans[i] = {tmp, arr[i]};
	}

	// 배열 추적하기
	int k = lis_size;
	for (int i = n - 1; i >= 0; i--)
	{
		if (k == 0)
			break;
		if (ans[i].first == k - 1)
		{
			k--;
			res.push_back(ans[i].second);
		}
	}
}
int main()
{
	init();
	solve();
	cout << lis_size << endl;
	for (int i = res.size() - 1; i >= 0; i--)
		cout << res[i] << ' ';
	return 0;
}