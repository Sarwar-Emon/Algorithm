#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 20;
vector<int> adj[N];
bool visited[N];

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int k;
    cin >> k;

    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
    }

    dfs(k);

    int count = 0;
    for (int v : adj[k])
    {
        if (visited[v])
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
