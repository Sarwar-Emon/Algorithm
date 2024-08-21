#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];

int BFS(int s, int d, int n) {
    if (s >= n || d >= n)
        return -1;

    vector<int> distance(n, -1);
    queue<int> q;

    q.push(s);
    distance[s] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adj[current]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);

                if (neighbor == d) {
                    return distance[neighbor];
                }
            }
        }
    }

    return distance[d];
}

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        int n, e;
        cin >> n >> e;

        // Clear the adjacency list for each test case
        for (int i = 0; i < N; ++i) {
            adj[i].clear();
        }

        // Construct the graph
        for (int i = 0; i < e; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int s, d;
        cin >> s >> d;

        int result = BFS(s, d, n);
        cout << result << endl;
    }

    return 0;
}
