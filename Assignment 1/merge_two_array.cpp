#include <iostream>
#include <climits>
using namespace std;

const int N = 1e5 + 7;
int a[N];

void Merge(int l, int r, int mid);

void mergeSort(int l, int r) {
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    Merge(l, r, mid);
}

void Merge(int l, int r, int mid) {
    int left_size = mid - l + 1;
    int right_size = r - mid;

    int L[left_size + 1];
    int R[right_size + 1];

    for (int i = 0; i < left_size; i++)
        L[i] = a[l + i];

    for (int j = 0; j < right_size; j++)
        R[j] = a[mid + 1 + j];

    L[left_size] = INT_MIN; 
    R[right_size] = INT_MIN; 

    int lp = 0, rp = 0;
    for (int k = l; k <= r; k++) {
        if (L[lp] >= R[rp]) {
            a[k] = L[lp];
            lp++;
        }
        else {
            a[k] = R[rp];
            rp++;
        }
    }
}

int main() {
    int n1, n2;
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cin >> a[i];
    }

    cin >> n2;
    for (int i = 0; i < n2; i++) {
        cin >> a[n1 + i];
    }
    int m=n1+n2;
    mergeSort(0, m - 1);
    
    for (int i = 0; i < m; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
