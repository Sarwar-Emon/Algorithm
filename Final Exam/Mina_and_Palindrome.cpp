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
        string s;
        cin >> s;
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int lps_length = dp[n][n];
        int min_time = n - lps_length;
        cout << min_time << endl;
    }
    return 0;
}
