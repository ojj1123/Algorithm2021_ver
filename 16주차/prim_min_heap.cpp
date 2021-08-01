#include <bits/stdc++.h>
using namespace std;

int n, m, ans;

vector<pair<int, int>> graph[1001];
bool vis[1001];
void init()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
}
void Prim()
{
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < graph[1].size(); i++)
    {
        int next = graph[1][i].first;
        int cost = graph[1][i].second;
        pq.push({-cost, next}); // {비용, 다음 정점}
    }
    vis[1] = 1;
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (!vis[cur])
        {
            vis[cur] = 1;
            ans += cost;
            for (int i = 0; i < graph[cur].size(); i++)
            {
                int next = graph[cur][i].first;
                int nextCost = graph[cur][i].second;
                if (!vis[next])
                    pq.push({-nextCost, next});
            }
        }
    }
}
int main()
{
    init();
    Prim();
    cout << ans;
}