#include <iostream>
#include <vector>
#include <stack>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
vector<vector<int>> adjListToMatrix(vector<vector<int>> &adjList, int n)
{
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    for(int i=0;i<n;i++)
    {
        for(int j: adjList[i])
        {
            adjMatrix[i][j-1]=1;
        }
    }
    return adjMatrix;
}
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adjList[u - 1].push_back(v);
    }

    vector<vector<int>> adjMatrix = adjListToMatrix(adjList, n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}