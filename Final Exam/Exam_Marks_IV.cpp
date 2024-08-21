#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;

int maxWaysToPerfectScore(int M, const vector<int>& marks) {
    vector<int> dp(1001, 0);
    dp[M] = 1; // Starting point

    for (int i = M; i <= 1000; ++i) {
        if (dp[i] > 0) {
            for (int mark : marks) {
                if (i + mark <= 1000) {
                    dp[i + mark] = (dp[i + mark] + dp[i]) % MOD;
                }
            }
        }
    }

    return dp[1000];
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> marks(N);
        for (int& mark : marks) {
            cin >> mark;
        }

        cout << maxWaysToPerfectScore(M, marks) << endl;
    }

    return 0;
}
