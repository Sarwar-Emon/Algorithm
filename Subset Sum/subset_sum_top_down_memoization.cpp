#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[10005][10005];
bool subset_sum(int n, int a[], int sum)
{
    if (n == 0)
    {
        if (sum == 0)

            return true;

        else
            return false;
    }
    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    if (a[n - 1] <= sum)
    {
        bool op1 = subset_sum(n - 1, a, sum - a[n - 1]);
        bool op2 = subset_sum(n - 1, a, sum);
        return dp[n][sum] = op1 || op2;
    }
    else
    {
        return dp[n][sum] = subset_sum(n - 1, a, sum);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum;
    cin >> sum;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            dp[i][j] = -1;
        }
    }
    if (subset_sum(n, a, sum))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}