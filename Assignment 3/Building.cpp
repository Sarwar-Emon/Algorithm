#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int a, b, w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

const int N = 1e5 + 5;
int parent[N];
int parentSize[N];

void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        parentSize[i] = 1;
    }
}

int dsu_find(int node)
{
    if (parent[node] != node)
    {
        parent[node] = dsu_find(parent[node]);
    }
    return parent[node];
}

void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> v;
    vector<Edge> ans;
    dsu_set(n);

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v.push_back(Edge(a, b, w));
    }

    sort(v.begin(), v.end(), cmp);

    int mst_cost = 0;
    int edges_used = 0;

    for (Edge val : v)
    {
        int a = val.a;
        int b = val.b;
        int w = val.w;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA != leaderB)
        {
            ans.push_back(val);
            mst_cost += w;
            dsu_union(a, b);
            edges_used++;
        }

        if (edges_used == n - 1)
        {
            break;
        }
    }

    if (edges_used != n - 1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << mst_cost << endl;
    }

    return 0;
}