// 시간복잡도 잘 구하기.
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dist(50, vector<int>(50, 0));
int board[52][52];
vector<pair<int, int>> house, chicken, chicken2; // 집 좌표, 치킨집 좌표
bool isused[15];
int n, m, chicken_cnt, ans = 5000;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int distance()
{
	int tmp, tot = 0;
	for (auto &h : house)
	{
		tmp = 5000;
		for (auto &c : chicken2)
		{
			tmp = min(tmp, abs(h.first - c.first) + abs(h.second - c.second)); // 각 집에 대한 각 치킨집의 거리의 최소
		}
		tot += tmp;
	}
	return tot;
}
void solve(int num, int k)
{
	if (k == m)
	{ // 치킨집을 m개 남기고 폐업
		int tmp = distance();
		ans = min(tmp, ans);
		return;
	}
	for (int i = num; i < chicken_cnt; i++)
	{
		if (!isused[i])
		{
			int cx = chicken[i].first;
			int cy = chicken[i].second;
			isused[i] = 1;
			chicken2.push_back({cx, cy}); // 남길 치킨집
			solve(i + 1, k + 1);
			chicken2.pop_back();
			isused[i] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
				house.push_back({i, j}); // 집 좌표
			else if (board[i][j] == 2)
			{
				chicken.push_back({i, j});
				chicken_cnt++;
			}
		}
	}
	solve(0, 0);
	cout << ans;
}