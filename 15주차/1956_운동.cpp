#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int INF = 4000003;
int n, m, ans = INF;
int board[405][405];
void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fill(board[i], board[i] + n + 1, INF);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        board[a][b] = c;
    }
}
void floydWarshall()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (board[i][j] > board[i][k] + board[k][j])
                    board[i][j] = board[i][k] + board[k][j];
            }
        }
    }
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, board[i][i]);
    }
    if (ans >= INF)
        cout << -1;
    else
        cout << ans;
}
int main()
{
    init();
    floydWarshall();
    solve();
    return 0;
}