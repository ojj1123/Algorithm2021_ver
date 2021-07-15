#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int n;
double res;
vector<pair<double, double>> board;
vector<pair<double, pair<int, int>>> vec;
int parent[101];
int level[101];
int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}
void merge(int u, int v) {
    u=find(u);
    v=find(v);
    if(u==v) return;
    if(level[u]>level[v]) swap(u, v);
    parent[u]=v;
    if(level[u]<=level[v]) level[v]++;
}
bool isSameSet(int u, int v) {
    u=find(u);
    v=find(v);
    if(u==v) return 1;
    return 0;
}
void kruskal() {
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            double x1=board[i].first, x2=board[j].first;
            double y1=board[i].second, y2=board[j].second;
            double dist=sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
            vec.push_back({dist,{i, j}});
        }
    }
    sort(vec.begin(), vec.end());
    int tmp=0;
    for(int i=0;i<vec.size();i++) {
        double cost=vec[i].first;
        int a=vec[i].second.first, b=vec[i].second.second;
        if(!isSameSet(a, b)) {
            merge(a, b);
            res+=cost;
            tmp++;
        }
        if(tmp==n-1) break;
    }
}
void init() {
    cin>>n;
    for(int i=0;i<n;i++) {
        double x, y;
        cin>>x>>y;
        board.push_back({x, y});
    }
    for(int i=0;i<n;i++) parent[i]=i;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    kruskal();
    cout<<res;
}