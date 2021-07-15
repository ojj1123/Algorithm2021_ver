#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, k, res;
string str[52];
bool isused[26];
void init() {
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>str[i];
    isused['a'-'a'] = isused['n'-'a'] = isused['t'-'a'] = isused['i'-'a'] = isused['c'-'a'] = 1;
}
void solve(int cnt, int idx) {
    if(cnt == k-5) {
        int tmp=0;
        for(int i=0;i<n;i++) {
            int len=str[i].size();
            bool flag = true;
            for(int j=4;j<len-4;j++) { // 문자열 안의 각 단어마다 순회
                flag=true;
                if(!isused[str[i][j]-'a']) { // 배우지 않았을 때,
                    flag=false;
                    break;
                }
            }
            if(flag) tmp++;
        }
        res = max(res, tmp);
        return;
    }
    for(char i=idx;i<26;i++) {
        if(!isused[i]) {
            isused[i]=1;
            solve(cnt+1, i+1);
            isused[i]=0;
        }
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    if(k<5) cout << 0;
    else if(k == 26) cout<<n;
    else {
        solve(0, 0);
        cout<<res;
    }
}