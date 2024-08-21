#include <iostream>
#include <climits>
using namespace std;

const int N = 1e5 + 7;
int a[N];

void Merge(int l, int r, int mid);

void mergeSort(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    Merge(l, r, mid);
}

void Merge(int l, int r, int mid)
{
    int left_size = mid - l + 1;
    int right_size = r - mid;

    int L[left_size], R[right_size];

    for (int i = 0; i < left_size; i++)
        L[i] = a[l + i];

    for (int j = 0; j < right_size; j++)
        R[j] = a[mid + 1 + j];

    int lp = 0, rp = 0, k = l;
    while (lp < left_size && rp < right_size)
    {
        if (L[lp] >= R[rp]) 
        {
            a[k++] = L[lp++];
        }
        else
        {
            a[k++] = R[rp++];
        }
    }

    while (lp < left_size)
    {
        a[k++] = L[lp++];
    }
    
    while (rp < right_size)
    {
        a[k++] = R[rp++];
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}