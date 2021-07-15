#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 150000

int idx, n;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool outOfBound(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= n) return 1;
    return 0;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(1) {
        cin>>n;
        if(n==0) break;
        vector<vector<int>> board(n, vector<int> (n));
        vector<vector<int>> d(n, vector<int> (n, INF));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++)
                cin>>board[i][j];
        }
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({-board[0][0], {0, 0}});
        d[0][0]=board[0][0];
        while(!pq.empty()) {
            int dist = -pq.top().first;
            int cx = pq.top().second.first;
            int cy = pq.top().second.second;
            pq.pop();
            if(d[cx][cy] < dist) continue;
            
            for(int dir=0;dir<4;dir++) {
                int nx=cx+dx[dir], ny=cy+dy[dir];
                if(outOfBound(nx, ny)) continue;
                int cost = dist + board[nx][ny];
                if(cost < d[nx][ny]) {
                    d[nx][ny] = cost;
                    pq.push({-cost, {nx, ny}});
                }
            }
        }
        cout << "Problem " << ++idx << ": " << d[n-1][n-1] << endl;
    }
}