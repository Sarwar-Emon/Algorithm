#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
vector<vector<int>> MatrixToList(int node)
{
    vector<vector<int>> adjList(node + 1);

    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
        {
            int edges;
            cin >> edges;
            if (edges == 1)
            {
                adjList[i].push_back(j);
            }
        }
    }
    return adjList;
}

void printAdjacencyList(vector<vector<int>> &adjList)
{
    for (int i = 1; i < adjList.size(); i++)
    {
         cout << "List " << i << " : ";
        if (adjList[i].empty())
        {
            cout << endl;
            continue;
        }
        for (int j : adjList[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    int node;
    cin>>node;
    vector<vector<int>> adjList= MatrixToList(node);
    printAdjacencyList(adjList);
    return 0;
}