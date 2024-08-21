#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1000;
vector<int> adj[N];

int BFS(int s, int d, int n)
{
    if (s >= n || d >= n)
        return -1;
    if (s == d)
        return 0;
    vector<int> distance(n, -1);
    queue<int> q;
    q.push(s);
    distance[s] = 0;

    while (!q.empty())
    {
        int s = q.front();
        q.pop();

        for (int v : adj[s])
        {
            if (distance[v] == -1)
            {
                distance[v] = distance[s] + 1;
                q.push(v);

                if (v == d)
                {
                    return distance[v];
                }
            }
        }
    }

    return -1;
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < n; ++i)
    {
        adj[i].clear();
    }

    for (int i = 0; i < e; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i)
    {
        int s, d;
        cin >> s >> d;

        int result = BFS(s, d, n);
        cout << result << endl;
    }

    return 0;
}
