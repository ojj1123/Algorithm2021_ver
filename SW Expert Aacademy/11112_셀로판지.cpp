#include<bits/stdc++.h>
using namespace std;

int t;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>t;
    for(int i=0;i<t;i++) {
        vector<pair<int, int>> point(4);
        int p, q, r, a, b, c, d, mx = 0, mn;
        char res1, res2;
        cin>>p>>q>>r>>a>>b>>c>>d;
        point[0]={a, b};
        point[1]={a, d};
        point[2]={c, b};
        point[3]={c, d};
        for(int j=0;j<4;j++) {
            auto cur=point[j];
            int dist=pow(cur.first-p, 2)+pow(cur.second-q, 2);
            mx=max(mx, dist); // 꼭짓점 중 최대길이의 제곱
        }
        if(a<=p && p<=c && b<=q && q<=d) { // 사각형 안에 원의 중심이 존재한다면
            mn=min(abs(a-p), abs(c-p));
            mn=min(mn, abs(b-q));
            mn=min(mn, abs(d-q)); // 내부 점일때 
            if(mx<=r*r) res1='Y', res2='N';
            else if(mn<r) res1='Y', res2='Y';
            else res1='N', res2='Y';
        }
        else {
            res1='Y';
            if(mx>r*r) res2='Y';
            else res2='N';
        }
        cout<<"#"<<i+1<<' '<<res1<<res2<<'\n';
    }
}