#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1001;
vector<int> adj[N];
vector<bool> visited(N, false);

int dfs(int u)
{
    int count = 1;
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            count += dfs(v);
        }
    }
    return count;
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> nodes;
    for (int i = 0; i < e; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

        if (find(nodes.begin(), nodes.end(), a) == nodes.end())
        {
            nodes.push_back(a);
        }
        if (find(nodes.begin(), nodes.end(), b) == nodes.end())
        {
            nodes.push_back(b);
        }
    }

    vector<int> component_sizes;
    for (int node : nodes)
    {
        if (!visited[node])
        {
            int component_size = dfs(node);
            if (component_size > 1)
            {
                component_sizes.push_back(component_size);
            }
        }
    }

    sort(component_sizes.begin(), component_sizes.end());

    if (component_sizes.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        for (int size : component_sizes)
        {
            cout << size << " ";
        }
        cout << endl;
    }

    return 0;
}
