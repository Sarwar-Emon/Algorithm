#include <iostream>
using namespace std;

const int N = 1e3 + 5;
int adj_Mat[N][N];

int main()
{
    int node, edges;
    cin >> node >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj_Mat[u][v] = w;

        // for directed graph
        // adj_Mat[v][u]=1;
    }
    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
        {
            cout << adj_Mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}