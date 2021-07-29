#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a[11][11];     // 주는 양분
int board[11][11]; // 양분
vector<int> tree[11][11];
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {1, 0, -1, -1, -1, 0, 1, 1};
void init()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
        fill(board[i], board[i] + n + 1, 5);
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }
}
void springAndSummer()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int sz = tree[i][j].size();
            sort(tree[i][j].begin(), tree[i][j].end());
            if (sz) // 그곳에 나무가 있다면,
            {
                int tmp = -1;
                for (int t = 0; t < sz; t++)
                {
                    if (board[i][j] - tree[i][j][t] >= 0)
                    {
                        board[i][j] -= tree[i][j][t];
                        tree[i][j][t]++;
                    }
                    else
                    {
                        tmp = t;
                        break;
                    }
                }
                // 죽은 나무가 있다면 양분으로 만들기(summer)
                if (tmp >= 0)
                {
                    for (int t = tmp; t < sz; t++)
                    {
                        int wood = tree[i][j].back() / 2;
                        board[i][j] += wood;
                        tree[i][j].pop_back();
                    }
                }
            }
        }
    }
}
void growTree(int x, int y)
{
    for (int dir = 0; dir < 8; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 1 || nx > n || ny < 1 || ny > n)
            continue;
        tree[nx][ny].push_back(1);
    }
}
void autumn()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int sz = tree[i][j].size();
            if (sz)
            {
                for (int t = 0; t < sz; t++)
                {
                    if (tree[i][j][t] != 0 && tree[i][j][t] % 5 == 0)
                        growTree(i, j);
                }
            }
        }
    }
}
void winter()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            board[i][j] += a[i][j];
}
void solve()
{
    while (k--)
    {
        springAndSummer();
        autumn();
        winter();
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int sz = tree[i][j].size();
            if (sz)
                ans += sz;
        }
    }
    cout << ans;
}
int main()
{
    init();
    solve();
}