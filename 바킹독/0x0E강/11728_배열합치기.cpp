#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
int n, m;
int a[MAX+2], b[MAX+2];
vector<int> vec;
void init() {
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    sort(a, a+n);
    sort(b, b+m);
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    int aidx=0, bidx=0;
    for(int i=0;i<n+m;i++) {
        if(aidx==n) vec.push_back(b[bidx++]);
        else if(bidx==m) vec.push_back(a[aidx++]);
        else if(a[aidx]<=b[bidx]) vec.push_back(a[bidx++]);
        else vec.push_back(b[bidx++]);
    }
    for(int i=0;i<vec.size();i++) cout<<vec[i]<<' ';
}