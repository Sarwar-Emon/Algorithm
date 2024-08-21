#include <iostream>
#include <vector>
#include <queue>
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

int bfs(int start_i, int start_j)
{
    queue<pair<pii, int>> q; // Queue to store current position and step count
    q.push({{start_i, start_j}, 0});
    visited[start_i][start_j] = true;

    while (!q.empty())
    {
        auto [pos, steps] = q.front();
        q.pop();

        int x = pos.first;
        int y = pos.second;

        // If we reach the end
        if (g[x][y] == 'e')
        {
            return steps;
        }

        // Explore all four directions
        for (auto d : direc)
        {
            int nx = x + d.first;
            int ny = y + d.second;

            if (isValid(nx, ny) && !visited[nx][ny] && g[nx][ny] != 'x')
            {
                visited[nx][ny] = true;
                q.push({{nx, ny}, steps + 1});
            }
        }
    }

    return -1; // No path found
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
            {
                start = {i, j};
            }
        }
        g[i] = x;
    }

    // Initialize visited array to false using memset
    memset(visited, 0, sizeof(visited));

    int result = bfs(start.first, start.second);
    cout << result << endl;

    return 0;
}
