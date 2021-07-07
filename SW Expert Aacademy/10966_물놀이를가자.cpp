#include<bits/stdc++.h>
using namespace std;

int t, n, m, res;
char board[1003][1003];
int dist[1003][1003];
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>t;
    for(int k=0;k<t;k++) {
        res = 0;
        queue<pair<int, int>> q;
        cin>>n>>m;
        for(int i=0;i<n;i++) fill(dist[i], dist[i]+m, -1);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>board[i][j];
                if(board[i][j]=='W') {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            int cx = cur.first, cy = cur.second;
            for(int dir = 0;dir < 4;dir++) {
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny > m) continue;
                if(dist[nx][ny] != -1 || board[nx][ny] != 'L') continue;
                q.push({nx, ny});
                dist[nx][ny] = dist[cx][cy] + 1;
                res += dist[nx][ny];
            }
        }
        cout<<"#"<<k+1<<' '<<res<<'\n';
    }
}