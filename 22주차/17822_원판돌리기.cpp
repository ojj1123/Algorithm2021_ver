#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, m, t, N;
vector<deque<int>> board(55);
void init() {
    cin >> n >> m >> t;
    N = n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            board[i].push_back(num);
        }
}
void rotate(int x, int d, int k) {
    if (d) {
        for (int i = x; i <= n; i += x) {
            for (int j = 0; j < k; j++) {
                int tmp = board[i].front();
                board[i].pop_front();
                board[i].push_back(tmp);
            }
        }
    } else {
        for (int i = x; i <= n; i += x) {
            for (int j = 0; j < k; j++) {
                int tmp = board[i].back();
                board[i].pop_back();
                board[i].push_front(tmp);
            }
        }
    }
}
void doSameNum() {
    vector<deque<int>> test;
    test = board;
    int cnt = 0;
    bool flag = 0;
    // 같은 원판 내에서
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) continue;
            if (j == 0) {
                if (board[i][j] == board[i][m - 1]) {
                    test[i][j] = 0;
                    test[i][m - 1] = 0;
                    flag = 1;
                }
                if (board[i][j] == board[i][1]) {
                    test[i][j] = 0;
                    test[i][1] = 0;
                    flag = 1;
                }
            } else if (j == m - 1) {
                if (board[i][j] == board[i][0]) {
                    test[i][j] = 0;
                    test[i][0] = 0;
                    flag = 1;
                }
                if (board[i][j] == board[i][m - 2]) {
                    test[i][j] = 0;
                    test[i][m - 1] = 0;
                    flag = 1;
                }
            } else {
                if (board[i][j] == board[i][j - 1]) {
                    test[i][j] = 0;
                    test[i][j - 1] = 0;
                    flag = 1;
                }
                if (board[i][j] == board[i][j + 1]) {
                    test[i][j] = 0;
                    test[i][j + 1] = 0;
                    flag = 1;
                }
            }
        }
    }
    // 다른 원판 끼리
    for (int j = 0; j < m; j++) {
        for (int i = 1; i <= n; i++) {
            if (board[i][j] == 0) continue;
            if (i == 1) {
                if (board[i][j] == board[i + 1][j]) {
                    test[i][j] = 0;
                    test[i + 1][j] = 0;
                    flag = 1;
                }
            } else if (i == n) {
                if (board[i][j] == board[i - 1][j]) {
                    test[i][j] = 0;
                    test[i - 1][j] = 0;
                    flag = 1;
                }
            } else {
                if (board[i][j] == board[i + 1][j]) {
                    test[i][j] = 0;
                    test[i + 1][j] = 0;
                    flag = 1;
                }
                if (board[i][j] == board[i - 1][j]) {
                    test[i][j] = 0;
                    test[i - 1][j] = 0;
                    flag = 1;
                }
            }
        }
    }
    if (!flag) {  // 같은 적 없음
        int total = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0) {
                    cnt++;
                    continue;
                }
                total += board[i][j];
            }
        int totalCnt = n * m - cnt;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0) continue;
                if (board[i][j] * totalCnt > total)
                    board[i][j]--;
                else if (board[i][j] * totalCnt < total)
                    board[i][j]++;
            }
        }
    } else
        board = test;
}
void solve() {
    while (t--) {
        int x, d, k;
        cin >> x >> d >> k;
        rotate(x, d, k);
        doSameNum();
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++) res += board[i][j];
    cout << res;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}