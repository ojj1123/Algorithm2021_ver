// BOJ 1922_네트워크 연결
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF (ll)10e9

int n, m, ans;
int dist[1001];
bool seleted[1001];
vector<pair<int, int>> graph[1001];

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
    dist[1] = 0;
    seleted[1] = true;
    fill(dist, dist + n + 1, INF);
    // 노드 1과 연결된 정점의 거리로 초기화함.
    for (int i = 0; i < graph[1].size(); i++)
    {
        int Next = graph[1][i].first;
        int Distance = graph[1][i].second;
        // 두 정점에 대해 간선이 여러개 일 수 있음을 인지해야 한다.
        // 시작점(st)와 그와 연결된 어떤 정점에 대해서 최소인 간선을 저장해야한다.
        dist[Next] = min(dist[Next], Distance);
    }

    for (int i = 1; i <= n - 1; i++)
    {
        // 연결된 노드 중 간선의 가중치가 최소인 것 찾기.
        int Min_Cost = INF;
        int Min_Idx = -1;
        for (int j = 1; j <= n; j++)
        {
            if (seleted[j] == true)
                continue;
            if (Min_Cost > dist[j])
            {
                Min_Cost = dist[j];
                Min_Idx = j;
            }
        }
        // 만약 Min_Cost == INF 이거나 Min_Idx == -1 이면 모든 정점이 연결된 연결그래프가 아니라는 뜻!
        seleted[Min_Idx] = true;
        ans += Min_Cost;
        // 위 과정에서 고른 가중치가 최소인 노드와 그것과 연결된 노드의 가중치값 업데이트.
        for (int j = 0; j < graph[Min_Idx].size(); j++)
        {
            int Next = graph[Min_Idx][j].first;
            int Distance = graph[Min_Idx][j].second;
            if (seleted[Next] == true)
                continue;
            if (dist[Next] > Distance)
                dist[Next] = Distance;
        }
    }
}

int main()
{
    init();
    Prim();
    cout << ans;
}