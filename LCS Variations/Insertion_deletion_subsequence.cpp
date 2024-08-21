#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[1005][1005];

int minDistance(string a, int n, string b, int m)
{
    if (n == 0)
        return m; // If the first string is empty, insert all characters of the second string
    if (m == 0)
        return n; // If the second string is empty, delete all characters of the first string

    if (dp[n][m] != -1)
        return dp[n][m];

    if (a[n - 1] == b[m - 1])
    {
        return dp[n][m] = minDistance(a, n - 1, b, m - 1);
    }
    else
    {
        int insertOp = minDistance(a, n, b, m - 1);    // Insert operation
        int deleteOp = minDistance(a, n - 1, b, m);    // Delete operation
        int replaceOp = minDistance(a, n - 1, b, m - 1); // Replace operation

        return dp[n][m] = 1 + min({insertOp, deleteOp, replaceOp});
    }
}

int main()
{
    string a, b;
    cin >> a >> b;

    for (int i = 0; i <= a.size(); i++)
    {
        for (int j = 0; j <= b.size(); j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << minDistance(a, a.size(), b, b.size());
    return 0;
}
