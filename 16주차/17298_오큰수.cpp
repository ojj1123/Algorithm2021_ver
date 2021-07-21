#include <bits/stdc++.h>
using namespace std;

int n;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	stack<int> st;
	cin >> n;
	vector<int> a(n), res(n, -1);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		while (!st.empty() && a[st.top()] < a[i])
		{
			res[st.top()] = a[i];
			st.pop();
		}
		st.push(i);
	}
	for (int i = 0; i < n; i++)
		cout << res[i] << ' ';
	return 0;
}