#include<bits/stdc++.h>
using namespace std;

int n, m;
bool board[502][502];
void init() {
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        int a, b;
        cin>>a>>b;
        board[a][b] = 1;
    }
}
void flodyWashall() {
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(board[i][k] && board[k][j])
                    board[i][j] = 1;
            }
        }
    }
}
int solve() {
    int res = 0;
    for(int i=1;i<=n;i++) {
        int count = 0;
        for(int j=1;j<=n;j++) {
            if(board[i][j] || board[j][i]) count++;
        }
        if(count == n-1) res++;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    flodyWashall();
    cout<<solve();
}