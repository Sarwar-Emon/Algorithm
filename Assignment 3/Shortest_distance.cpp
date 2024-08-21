#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_map>
using namespace std;

#define pi pair<int, int>

const int N = 1e5 + 5;
vector<pi> adj[N];
unordered_map<int, vector<int>> all_dist;

void dijkstra(int s, int n)
{
    vector<int> dist(n + 1, INT_MAX);
    vector<bool> vis(n + 1, false);

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (vis[u])
            continue;
        vis[u] = true;

        for (pi edge : adj[u])
        {
            int b = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[b])
            {
                dist[b] = dist[u] + w;
                pq.push({dist[b], b});
            }
        }
    }
    all_dist[s] = dist;
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    int q;
    cin >> q;

    while (q--)
    {
        int source, destination;
        cin >> source >> destination;

        if (all_dist.find(source) == all_dist.end())
        {

            dijkstra(source, n);
        }

        if (all_dist[source][destination] == INT_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << all_dist[source][destination] << endl;
        }
    }

    return 0;
}
