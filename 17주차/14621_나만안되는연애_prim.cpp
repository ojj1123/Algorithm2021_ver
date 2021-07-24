// 틀림
#include <bits/stdc++.h>
using namespace std;
#define INF 1000005
int n, m;
bool gen[1001];
bool selected[1001];
int dist[1001];
vector<pair<int, int>> graph[1001];
void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if (c == 'M')
            gen[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (gen[a] == gen[b])
            continue;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
}

int prim(int st)
{
    int ans = 0;
    fill(dist, dist + n + 1, INF);
    fill(selected, selected + n + 1, false);
    dist[st] = 0;
    selected[st] = 1;
    for (int i = 0; i < graph[st].size(); i++)
    {
        int next = graph[st][i].first;
        int cost = graph[st][i].second;
        // 두 정점에 대해 간선이 여러개 일 수 있음을 인지해야 한다.
        // 시작점(st)와 그와 연결된 어떤 정점에 대해서 최소인 간선을 저장해야한다.
        dist[next] = min(dist[next], cost);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int min_cost = INF, min_idx = -1;
        for (int j = 1; j <= n; j++)
        {
            if (selected[j])
                continue;
            if (min_cost > dist[j])
            {
                min_cost = dist[j];
                min_idx = j;
            }
        }
        if (min_idx == -1)
            return -1;
        ans += min_cost;
        selected[min_idx] = 1;
        for (int j = 0; j < graph[min_idx].size(); j++)
        {
            int next = graph[min_idx][j].first;
            int cost = graph[min_idx][j].second;
            if (selected[next])
                continue;
            dist[next] = min(dist[next], cost);
        }
    }
    return ans;
}
int main()
{
    init();
    cout << prim(2);
    return 0;
}