#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];

void reverse_dfs(int u, stack<int> &reverseOrderStack)
{
    visited[u] = true;
    // Traverse adjacent nodes in reverse order
    for (int i = adj[u].size() - 1; i >= 0; i--)
    {
        int v = adj[u][i];
        if (!visited[v])
        {
            reverse_dfs(v, reverseOrderStack);
        }
    }
    // After traversing all adjacent nodes, push the current node onto the stack
    reverseOrderStack.push(u);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);

        // For undirected graph
        adj[v].push_back(u);
    }

    stack<int> reverseOrderStack;

    reverse_dfs(1, reverseOrderStack); // Start DFS from node 1

    // Print the nodes in reverse order
    cout << "Reverse Order of DFS Traversal: ";
    while (!reverseOrderStack.empty())
    {
        cout << reverseOrderStack.top() << " ";
        reverseOrderStack.pop();
    }
    cout << endl;

    return 0;
}
