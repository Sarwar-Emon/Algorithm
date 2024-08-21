#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 7;
const int INF = 1e9 + 7;
vector<pii> g[N];
vector<int> dist(N, INF);
vector<bool> visited(N);

void dijkstra(int source) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (pii vpair : g[u]) {
            int v = vpair.first;
            int w = vpair.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        //g[v].push_back({u, w});
    }

    int source, destination;
    cin >> source >> destination;

    dijkstra(source);

    if (dist[destination] == INF) {
        cout << "No path exists" << endl;
    } else {
        cout << "Shortest distance: " << dist[destination] << endl;
    }

    return 0;
}
