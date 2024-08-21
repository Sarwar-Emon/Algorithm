#include <iostream>
#include <vector>
#include <cstring> // For memset
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 10;
vector<string> g(N);
bool visited[N][N];
int n, m;
vector<pii> direc = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

bool dfs(int i, int j)
{
    if (!isValid(i, j))
        return false;
    if (visited[i][j])
        return false;
    if (g[i][j] == 'x')
        return false;

    visited[i][j] = true;

    if (g[i][j] == 'e')
        return true;

    for (auto d : direc)
    {
        if (dfs(i + d.first, j + d.second))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    cin >> n >> m;
    pii start;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        for (int j = 0; j < m; j++)
        {
            if (x[j] == 's')
            start = {i, j};
        }
        g.push_back(x);
    }

    // Initialize visited array to false using memset
    memset(visited, 0, sizeof(visited));

    if (dfs(start.first, start.second))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
