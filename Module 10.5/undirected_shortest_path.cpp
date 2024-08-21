#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;
const int N = 1e3 + 5;
const int INF = 1e9 + 7;
vector<p> g[N];
vector<int> dist(N, INF); // have to understand
vector<bool> visited(N);  // have to understand

void dijkstra(int s)
{
    priority_queue<p, vector<p>, greater<p>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;

        for (p vpair : g[u])
        {
            int v = vpair.first;
            int w = vpair.second;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u ]+ w;
                pq.push({dist[v], v});
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int source, destination;
    cin >> source >> destination;

    dijkstra(source);

    if (dist[destination] == INF)
    {
        cout << "No path exists" << endl;
    }
    else
    {
        cout << "Shortest distance: " << dist[destination] << endl;
    }
    return 0;
}