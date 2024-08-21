#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (a[i - 1] == b[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int lcs_length = dp[n][m];
        int scs_length = n + m - lcs_length;
        cout << scs_length << endl;
    }

    return 0;
}
