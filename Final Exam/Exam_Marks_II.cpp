#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
bool obtain_score(int M, vector<int> &marks)
{
    vector<bool> dp(1001, false);
    dp[M] = true;

    for (int i = M; i <= 1000; ++i)
    {
        if (dp[i])
        {
            for (int mark : marks)
            {
                if (i + mark <= 1000)
                {
                    dp[i + mark] = true;
                }
            }
        }
    }
    return dp[1000];
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> marks(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> marks[i];
        }

        if (obtain_score(m, marks))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
