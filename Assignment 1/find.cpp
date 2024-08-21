#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> &a, int k)
{
    int left = 0;
    int right = a.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (a[mid] == k)
        {
            return mid;
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
    return -1; 
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
    int result = binary_search(v, k);
    if (result != -1)
    {
        cout << "Index of " << k << " is " << result << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    return 0;
}
