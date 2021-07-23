// 적들을 전신시키는 것 == 궁수를 전진시키는 것
// 시간복잡도 잘 구해야 한다. 시간복잡도 잘못 구하면 풀이가 다른 곳으로 센다.
#include <bits/stdc++.h>
using namespace std;

int n, m, d, res;
vector<vector<int>> board(16, vector<int>(16)), tmp;
vector<int> v;
vector<pair<int, int>> killed;

void init()
{
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
}
bool outOfBound(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m)
		return 1;
	return 0;
}
int attack()
{
	int cnt = 0;
	for (int i = n; i >= 1; i--)
	{ // 궁수 위치 변화 == 턴 변화
		for (int num = 0; num < v.size(); num++)
		{ // 궁수 번호
			for (int dist = 1; dist <= d; dist++)
			{ // 거리
				bool flag = false;
				int x = i, y = v[num]; // 궁수 위치
				for (int l = 1; l <= 2 * dist - 1; l++)
				{
					int nx = (l <= dist ? x - l : x - (2 * dist - l));
					int ny = y + (l - dist);
					if (outOfBound(nx, ny))
						continue;
					if (board[nx][ny])
					{ // 공격하려는 곳에 적이 있다면
						flag = true;
						killed.push_back({nx, ny});
						break; // 공격하고 바로 그 궁수는 공격 종료해야함
					}
				}
				if (flag)
					break;
			}
		}
		int size = killed.size();
		for (int a = 0; a < size; a++)
		{
			if (board[killed[a].first][killed[a].second])
			{
				board[killed[a].first][killed[a].second] = 0;
				cnt++;
			}
		}
		killed.clear(); // 죽인 적 초기화
	}
	return cnt;
}
void solve(int y, int cnt)
{
	if (cnt == 3)
	{
		tmp = board;
		res = max(res, attack());
		board = tmp; // 원 상태로
		return;
	}
	for (int i = y; i < m; i++)
	{
		v.push_back(i);
		solve(i + 1, cnt + 1);
		v.pop_back();
	}
}
int main()
{
	init();
	solve(0, 0);
	cout << res;
	return 0;
}