#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;
vector<pair<int, int>> v;

bool cmpEdges(pair<int, int> a,  pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main()
{
    int E;
    cin >> E;

    for (int i = 0; i < E; ++i)
    {
        int A, B;
        cin >> A >> B;
        v.push_back({A, B});
    }

    sort(v.begin(), v.end(), cmpEdges);

    for (const auto edge : v)
    {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}