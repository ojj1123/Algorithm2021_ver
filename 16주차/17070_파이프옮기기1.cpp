// 내리막길 문제랑 유사
#include <bits/stdc++.h>
using namespace std;

int n;
int board[20][20];
int dp[20][20][3];
struct point
{
	int x;
	int y;
};
using p = point;
bool outOfBound(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= n)
		return 1;
	return 0;
}
p position(int x, int y, int dir)
{
	p ret;
	switch (dir)
	{
	case 0:
		ret = {x, y + 1};
		break;
	case 1:
		ret = {x + 1, y + 1};
		break;
	case 2:
		ret = {x + 1, y};
		break;
	}
	return ret;
}
void init()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	memset(dp, -1, sizeof(dp));
}
int dfs(int x, int y, int dir)
{
	if (x == n - 1 && y == n - 1)
		return 1;
	else if (dp[x][y][dir] == -1)
	{
		dp[x][y][dir] = 0;
		if (dir == 0)
		{
			for (int d : {0, 1})
			{
				p next = position(x, y, d);
				if (outOfBound(next.x, next.y) || board[next.x][next.y])
					continue;
				if (d == 1 && (board[x + 1][y] || board[x][y + 1]))
					continue;
				dp[x][y][dir] += dfs(next.x, next.y, d);
			}
		}
		else if (dir == 1)
		{
			for (int d : {0, 1, 2})
			{
				p next = position(x, y, d);
				if (outOfBound(next.x, next.y) || board[next.x][next.y])
					continue;
				if (d == 1 && (board[x + 1][y] || board[x][y + 1]))
					continue;
				dp[x][y][dir] += dfs(next.x, next.y, d);
			}
		}
		else
		{
			for (int d : {1, 2})
			{
				p next = position(x, y, d);
				if (outOfBound(next.x, next.y) || board[next.x][next.y])
					continue;
				if (d == 1 && (board[x + 1][y] || board[x][y + 1]))
					continue;
				dp[x][y][dir] += dfs(next.x, next.y, d);
			}
		}
	}
	return dp[x][y][dir];
}
int main()
{
	init();
	cout << dfs(0, 1, 0);
	return 0;
}