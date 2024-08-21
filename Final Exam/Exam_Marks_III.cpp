#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int min_step(int M, const vector<int> &marks)
{
    vector<int> dist(1001, INT_MAX);
    queue<int> q;

    q.push(M);
    dist[M] = 0;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int mark : marks)
        {
            int next = current + mark;
            if (next <= 1000 && dist[next] == INT_MAX)
            {
                dist[next] = dist[current] + 1;
                q.push(next);
            }
        }
    }
    if (dist[1000] == INT_MAX)
    {
        return -1;
    }
    else
    {
        return dist[1000];
    }
}
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        vector<int> marks(N);
        for (int &mark : marks)
        {
            cin >> mark;
        }
        int result = min_step(M, marks);
        cout << result << endl;
    }
    return 0;
}
