#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;
bool vis[102][102];
bool outOfBound(int x, int y) {
    if(x<0 || x>100 || y<0 || y>100) return 1;
    return 0;
}
void makeZeroGen(vector<pair<int, int>> &v, int x, int y, int dir) {
    int i, j;
    if(dir==0 && !outOfBound(x+1, y)) i=x+1, j=y;
    else if(dir==1 && !outOfBound(x, y-1)) i=x, j=y-1;
    else if(dir==2 && !outOfBound(x-1, y)) i=x-1, j=y;
    else if(dir==3 && !outOfBound(x, y+1)) i=x, j=y+1;
    v.push_back({i, j});
    vis[j][i]=1;
}
int countSqure() {
    int cnt=0;
    for(int i=1;i<=100;i++) {
        for(int j=1;j<=100;j++) {
            if(vis[i][j] && vis[i-1][j] && vis[i][j-1] && vis[i-1][j-1]) cnt++;
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    while(n--) {
        int x, y, d, g;
        vector<pair<int, int>> dragon;
        cin>>x>>y>>d>>g;
        dragon.push_back({x, y});
        vis[y][x]=1;
        makeZeroGen(dragon, x, y, d);
        for(int i=1;i<=g;i++) {
            auto center=dragon.back();
            vis[center.second][center.first]=1;
            int len=dragon.size();
            for(int j=len-2;j>=0;j--) {
                int tmpX = -dragon[j].second+center.second + center.first;
                int tmpY = dragon[j].first-center.first + center.second;
                if(!outOfBound(tmpX, tmpY)) {
                    dragon.push_back({tmpX, tmpY});
                    vis[tmpY][tmpX]=1;
                }
            }
        }
    }
    cout<<countSqure();
}