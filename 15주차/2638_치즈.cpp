#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, m, res;
int board[102][102];
int vis[102][102];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void input() {
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) {
            cin>>board[i][j];
        }
}
void bfs() {
    for(int i=0;i<n;i++) fill(vis[i], vis[i]+m, 0);
    queue<pair<int, int>> q;
    q.push({0,0});
    vis[0][0]=-1;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        int cx=cur.first, cy=cur.second;
        for(int dir=0;dir<4;dir++) {
            int nx=cx+dx[dir], ny=cy+dy[dir];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(vis[nx][ny] < 0 || board[nx][ny] > 0) continue;
            vis[nx][ny]=-1;
            q.push({nx, ny});
        }
    }
}
bool removeCheeze() {
    queue<pair<int, int>> cheeze;
    vector<pair<int, int>> vec;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(board[i][j]==1) {
                int cnt = 0;
                for(int dir=0;dir<4;dir++) {
                    int nx=i+dx[dir], ny=j+dy[dir];
                    if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                    if(vis[nx][ny] == -1) cnt++;
                }
                if(cnt>=2) vec.push_back({i, j}); // 지울 치즈
            }
        }
    }
    int size = vec.size();
    if(size == 0) return 1;
    else {
        for(int i=0;i<size;i++) {
            int x = vec[i].first, y = vec[i].second;
            board[x][y] = 0;
        }
        return 0;
    }
}
void solve() {
    input();
    while(1) {
        res++;
        bfs(); // 공기 중에 있는 부분 -1로 바꾸기
        if(removeCheeze()) break;
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<m;j++) cout<<vis[i][j]<<' ';
        //     cout<<endl;
        // }
        // cout<<endl;
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    cout << res - 1;
}