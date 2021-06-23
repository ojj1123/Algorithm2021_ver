// 소수 중 최소 경로 ==> BFS 인 것을 알아야 한다!
// 에라토스테네스의 체 정확하게 알게 됨.
#include <bits/stdc++.h>
using namespace std;

int t, cnt;
int a, b;
bool prime[10002];
int vis[10002];
void setPrime() {
    // 소수 : false , 합성수 : true -> 소수 합성수를 정하고 가야함.
    for (int i = 2; i * i <= 10000; i++) {
        if (prime[i]) continue;
        for (int j = i * i; j <= 10000; j += i) {
            prime[j] = 1;
        }
    }
}
void bfs() {
    queue<int> q;
    fill(vis, vis + 10002, 0);
    vis[a] = 1;
    q.push(a);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        string curStr = to_string(cur);
        if (cur == b) {
            cout << vis[cur] - 1 << '\n';
            return;
        }
        for (int i = 0; i < 4; i++) {
            string tmp = string(curStr);
            for (char j = '0'; j <= '9'; j++) {
                tmp[i] = j;
                int temp = stoi(tmp);
                if (!vis[temp] && temp >= 1000 && !prime[temp]) {
                    vis[temp] = vis[cur] + 1;
                    q.push(temp);
                }
            }
        }
    }
    cout << "Impossible\n";
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    setPrime();
    cin >> t;
    while (t--) {
        cin >> a >> b;
        bfs();
    }
}