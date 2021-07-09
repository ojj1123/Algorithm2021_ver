#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int v, e, t;
vector<int> graph[20002];
int vis[20002];

void dfs(int v, int color) {
    vis[v]=color;
    for(int i=0;i<graph[v].size();i++) {
        int nx = graph[v][i];
        if(!vis[nx]) dfs(nx, -color);
    }
}
bool isBipartite() {
    for(int i=1;i<=v;i++) {
        for(int j=0;j<graph[i].size();j++) {
            int nx = graph[i][j];
            if(vis[i] == vis[nx]) return 0;
        }
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--) {
        cin>>v>>e;
        fill(vis, vis+v+1, 0);
        for(int i=1;i<=v;i++) graph[i].clear();
        for(int i=0;i<e;i++) {
            int a, b; cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=1;i<=v;i++) {
            if(vis[i] == 0) dfs(i, 1);
        }
        cout<<(isBipartite() ? "YES\n":"NO\n");
    }
}