// 무방향 그래프에서 사이클 판별하고 사이클 추적하기.
/*
    이 문제를 통해 배운 점
    - 트리는 정점 n개, 간선 n-1개인 그래프라는 것을 이용하여, 만약 간선이 n개라면,
    무조건 사이클이 생길 수 밖에 없다.
    - 사이클의 정점을 추적할 때 부모 정점을 저장해본다.
*/

/*
    방향그래프에서 사이클 판별
    11057_텀프로젝트
    scpc2021 round1 No Cycle
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n;
vector<int> graph[3002];
bool vis[3002];
int parent[3002];
int d[3002];
bool flag;
queue<int> q;

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    fill(d, d + n + 1, -1);
}
void noteCycle(int now, int next) {
    q.push(now);
    d[now] = 0;
    if (now == next) return;
    noteCycle(parent[now], next);
}
void dfs(int now, int from) {
    vis[now] = 1;
    for (int i = 0; i < graph[now].size(); i++) {
        int next = graph[now][i];
        if (!vis[next]) {
            parent[next] = now;
            dfs(next, now);
        } else if (next != from && !flag) {
            flag = 1;
            noteCycle(now, next);
        }
    }
}
void solve() {
    parent[1] = 1;
    dfs(1, 1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (d[next] != -1) continue;
            d[next] = d[cur] + 1;
            q.push(next);
        }
    }
    for (int i = 1; i <= n; i++) cout << d[i] << ' ';
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}