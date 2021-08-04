/*
    <후기>
    엄청난 구현력을 요구한 문제였다. 변수들이 너무 많았다.
    내가 짠 논리를 코드로 옮기는 것이 어려웠다.
    결국, 다른 사람 코드를 참고했다.
    내가 생각한 논리와 비슷하나 나는 코드로 옮기지 못했다.
    사실 먼저 굴러가야하는 구슬을 정해야 한다고는 생각했다. 코드로 구현하는 것은
    생각보다 간단했다. 방향에 따라 인덱스만 비교해주면 되는 문제였다. 왜 이 간단한
    것을 못했나..싶다..
    내가 생각하지 못했던 것은 구슬을 실제로 그곳에 배치하지 못한 부분이었다.
    먼저 굴러간 구슬을 배치했다면, 나중에 굴러가는 구슬이 어디까지 가야할지 쉽게 해결할
    수 있었을 것이다.
    또 움직일 수 있는 횟수만큼 반복을 돌리는 부분을 어떻게 구현해야 할지 막혔다. 
    내가 한 방식은 vis 배열에 움직인 숫자를 적는 방식이었다.(vis[next] = vis[cur] + 1 이런식으로)
    하지만 지금 이 코드에서는 그냥 10회로 제한하고, q.size()만큰 돌리고 다 돌렸드면 1회 증가하는
    방식이다. 어디서 본 방식(?)같지만 기억은 아지 않는다. 일단 이런 방식도 있다는 것을 기억해두자.
    
    무엇이 부족했던 것일까? 내가 기억해야 할 부분을 적어보자.
    - BFS에서 횟수가 정해진 부분을 처리한 방식
    - 구슬을 배치하고 다 돌았으면 다시 삭제하는 부분
    
    https://jaimemin.tistory.com/1343

*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using pii = pair<int, int>;

int n, m;
char board[13][13];
pii red, blue;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[13][13][13][13];

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] != 'R' && board[i][j] != 'B') continue;
            board[i][j] == 'R' ? red = {i, j} : blue = {i, j};
            board[i][j] = '.';
        }
    }
}

void solve() {
    queue<pair<pii, pii>> q;
    q.push({red, blue});
    vis[red.first][red.second][blue.first][blue.second] = 1;
    for (int t = 0; t < 10; t++) {
        int qsz = q.size();
        for (int i = 0; i < qsz; i++) {
            auto curRed = q.front().first;
            auto curBlue = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int gameOver[2] = {0};
                int idx = 0;  // 0 : red, 1 : blue
                // 방향마다 먼저 갈 구슬 인덱스 정하기
                if ((k == 0 && curBlue.first > curRed.first) || (k == 1 && curBlue.second > curRed.second) || (k == 2 && curBlue.first < curRed.first) || (k == 3 && curBlue.second < curRed.second)) idx++;
                // 공굴리기
                int nextx[2] = {curRed.first, curBlue.first};
                int nexty[2] = {curRed.second, curBlue.second};

                for (int s = 0; s < 2; s++) {
                    while (1) {
                        if (board[nextx[idx]][nexty[idx]] != '.') break;  // # or O or 먼저 굴러간 구슬
                        nextx[idx] += dx[k];
                        nexty[idx] += dy[k];
                    }
                    if (board[nextx[idx]][nexty[idx]] == 'O') {
                        gameOver[idx] = 1;  // 해당 구슬 구멍에 빠짐
                    } else {
                        nextx[idx] -= dx[k];
                        nexty[idx] -= dy[k];
                        board[nextx[idx]][nexty[idx]] = idx == 0 ? 'R' : 'B';
                    }
                    idx = 1 - idx;
                }
                // 게임 종료 빨간 구슬 빠지고 파란구슬은 안빠짐
                if (gameOver[0] && !gameOver[1]) {
                    cout << 1;
                    return;
                }
                for (int s = 0; s < 2; s++)
                    if (!gameOver[s]) board[nextx[s]][nexty[s]] = '.';  // 구멍이 아니라면, 구슬이 굴러간 곳이므로 다시 원상복구
                if (!gameOver[1]) {                                     // 파란 공이 구멍에 안빠졌을 때
                    if (vis[nextx[0]][nexty[0]][nextx[1]][nexty[1]]) continue;
                    vis[nextx[0]][nexty[0]][nextx[1]][nexty[1]] = 1;
                    q.push({{nextx[0], nexty[0]}, {nextx[1], nexty[1]}});
                }
            }
        }
    }
    cout << 0;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}