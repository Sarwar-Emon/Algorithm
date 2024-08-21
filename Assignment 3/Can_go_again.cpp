#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <algorithm>
#include<limits.h>
using namespace std;

class Edge
{
public:
    int u, v, w;
    Edge(int u,int v,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
};

const int INF = INT_MAX;
const int MAX_N = 1000;
int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edges;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back(Edge(a, b, w));
    }

    int source;
    cin >> source;

    int dist[MAX_N + 1];
    fill(dist, dist + n + 1, INF);
    dist[source] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (const Edge &ed : edges)
        {
            int a = ed.u;
            int b = ed.v;
            int w = ed.w;
            if (dist[a] != INF && dist[a] + w < dist[b])
            {
                dist[b] = dist[a] + w;
            }
        }
    }

    bool negativeCycle = false;
    for (const Edge &ed : edges)
    {
        int a = ed.u;
        int b = ed.v;
        int w = ed.w;
        if (dist[a] != INF && dist[a] + w < dist[b])
        {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        int t;
        cin >> t;
        while (t--)
        {
            int dest;
            cin >> dest;
            if (dist[dest] == INF)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dist[dest] << endl;
            }
        }
    }

    return 0;
}
