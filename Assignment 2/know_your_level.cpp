#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

const int M = 100001;
vector<int> adj[M];

vector<int> find_pizza_shops_at_level(int s, int level)
{
    vector<int> distance(M, -1);
    queue<int> q;
    q.push(s);
    distance[s] = 0;

    vector<int> result;

    while (!q.empty())
    {
        int s = q.front();
        q.pop();

        int current_level = distance[s];

        if (current_level == level)
        {
            result.push_back(s);
        }
        else if (current_level > level)
        {
            break;
        }

        for (int v : adj[s])
        {
            if (distance[v] == -1)
            {
                distance[v] = current_level + 1;
                q.push(v);
            }
        }
    }

    return result;
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int L;
    cin >> L;

    if (n == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    int s = 0;
    for (int i = 0; i < M; ++i)
    {
        if (!adj[i].empty())
        {
            s = i;
            break;
        }
    }

    vector<int> shops_at_level = find_pizza_shops_at_level(s, L);

    if (shops_at_level.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        for (int shop : shops_at_level)
        {
            cout << shop << " ";
        }
        cout << endl;
    }

    return 0;
}
