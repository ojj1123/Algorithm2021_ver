#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 1000000000

int t, n;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int charToNumber(char c) {
    return c - '0';
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>t;
    for(int k=0;k<t;k++) {
        cin>>n;
        vector<string> board(n+2);
        vector<vector<int>> vis(n+1, vector<int>(n+1, MAX));
        for(int i=0;i<n;i++) cin>>board[i];
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0]=charToNumber(board[0][0]);
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            int cx=cur.first, cy=cur.second;
            for(int dir=0;dir<4;dir++) {
                int nx=cx+dx[dir], ny=cy+dy[dir];
                if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
                if(vis[nx][ny] <= vis[cx][cy]+charToNumber(board[nx][ny])) continue;
                vis[nx][ny] = vis[cx][cy]+charToNumber(board[nx][ny]);
                q.push({nx, ny});
            }
        }
        cout<<"#"<<k+1<<' '<<vis[n-1][n-1]<<endl;
    }
}