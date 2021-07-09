// 21년 7월 9일 금요일... 드.디.어. dp를 누구의 도움도 받지 않고 나 혼자 풀.었.다.
// 비슷한 문제 : 계단 오르기
#include<bits/stdc++.h>
using namespace std;

int n;
int dp[10002];
int arr[10002];
void input() {
    cin >> n;
    for(int i=1;i<=n;i++) cin>>arr[i];
}
void solve() {
    dp[1]=arr[1];
    dp[2]=arr[1] + arr[2];
    for(int i=3;i<=n;i++)
        dp[i]=max(max(dp[i-3]+arr[i-1], dp[i-2])+arr[i], dp[i-1]);
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    input();
    solve();
    cout<<dp[n];
}