#include <iostream>
#include <vector>
using namespace std;

// bam pashe
int bam_pash(vector<int> &a, int k)
{
    int left = 0;
    int right = a.size() - 1;
    int result = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (a[mid] == k)
        {
            result = mid;
            right = mid - 1;
        }
        else if (a[mid] < k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return result;
}
//dan pashe
int dan_pash(vector<int> &a, int k)
{
    int left = 0;
    int right = a.size() - 1;
    int result = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (a[mid] == k)
        {
            result = mid;
            left = mid + 1;
        }
        else if (a[mid] < k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int k;
    cin >> k;
    int leftSide = bam_pash(v, k);
    int rightSide = dan_pash(v, k);

    if (leftSide != rightSide)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
