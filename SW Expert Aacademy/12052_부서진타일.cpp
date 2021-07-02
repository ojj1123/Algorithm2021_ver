#include<bits/stdc++.h>
using namespace std;

int t, n, m;
int main() {
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>t;
    for(int i=0;i<t;i++) {
        cin>>n>>m;
        bool flag = true;
        string board[52];
        int vis[52][52];
        for(int j=0;j<n;j++) fill(vis[i], vis[i]+m, 0);
        for(int j=0;j<n;j++) cin>>board[j];
        for(int j=0;j<n-1;j++) {
            for(int k=0;k<m-1;k++) {
                if(board[j][k]=='#') {
                    if(!(board[j+1][k+1]=='#' && board[j][k+1] == '#' && board[j+1][k]=='#')) {
                        flag=false;
                        break;
                    }
                    else {
                        board[j][k]=board[j+1][k]=board[j][k+1]=board[j+1][k+1]='.';
                        k++;
                    }
                }
            }
            if(!flag) break;
        }
        for(int j=0;j<m;j++) {
            if(board[n-1][j]=='#') {
                flag=false;
                break;
            }
        }
        for(int j=0;j<n;j++) {
            if(board[j][m-1]=='#') {
                flag = false;
                break;
            }
        }
        cout<<"#"<<i+1<<' ';
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
}