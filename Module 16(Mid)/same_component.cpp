#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
#define pi pair<int, int>

const int N = 1005;
int n, m;
char a[N][N];
bool vis[N][N];
vector<pi> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int cI, int cJ)
{
    return cI >= 0 && cI < n && cJ >= 0 && cJ < m && a[cI][cJ] == '.';
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        pi p = path[i];
        int ci = si + p.first;
        int cj = sj + p.second;
        if (isValid(ci, cj) && !vis[ci][cj])
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int x1, y1, x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    dfs(x1, y1);

    if (vis[x2][y2])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
