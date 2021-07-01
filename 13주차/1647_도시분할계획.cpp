#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
int n, m, cnt, ans;
vector<int> parent(MAX+2), level(MAX+2, 0);
vector<pair<int, pair<int, int> > > vec;
void init() {
    for(int i=1;i<=n;i++) parent[i]=i;
    for(int i=0;i<m;i++) {
        int a, b, c;
        cin>>a>>b>>c;
        vec.push_back({c, {a, b}});
    }
    sort(vec.begin(), vec.end());
}
int find(int u) {
    if(u==parent[u]) return u;
    return parent[u]=find(parent[u]);
}
void merge(int u, int v) {
    u=find(u);
    v=find(v);
    if(u==v) return;
    if(level[u]>level[v]) swap(u, v);
    parent[u]=v;
    if(level[u]==level[v]) level[v]++;
}
bool isSameSet(int u, int v) {
    v=find(v);
    u=find(u);
    if(u==v) return true;
    return false;
}
int main() {
    cin>>n>>m;
    init();
    for(int i=0;i<vec.size();i++) {
        int cost=vec[i].first;
        int a=vec[i].second.first;
        int b=vec[i].second.second;
        if(isSameSet(a, b)) continue;
        merge(a, b);
        cnt++;
        ans+=cost;
        if(cnt==n-2) break;
    }
    cout<<ans;
    return 0;
}