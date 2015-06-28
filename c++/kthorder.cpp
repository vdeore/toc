/* problem:
 * Order Statistics. Kth Smallest or Largest Element in an Un-ordered Array.
 */
#include<iostream>
#include<algorithm>
using namespace std;

void print(int a[], int n) {
    cout <<"\n";
    for (int i = 0; i < n; ++i) {
        cout <<" "<<a[i];
    }
    cout <<"\n";
}

int partition(int *a, int l, int r) {
    int m, p;
    if (l == r) {
        return l;
    }
    m = (l+r)/2;
    p = a[m];
    while (l <= r) {
        while(l <= r && a[l] < p) ++l;
        while(l <= r && a[r] > p) --r;
        if (l <= r) {
            swap(a[l], a[r]);
            ++l; --r;
        }
    }
    return l;
}

int kthorder(int *a, int l, int r, int k) {
    int rank;

    rank = partition(a, l, r);
    if (rank == k-1) {
        return a[k-1];
    }
    if (rank < k-1) {
        return(kthorder(a, rank+1, r, k));
    } 
    return kthorder(a, l, rank-1, k);
}

main () {
    int k = 6;
    int a[] = {14,8,22,12,4,2,10};

    for (int i = 0; i < 7; ++i) {
    cout<<"\n"<<i<<"th-order stats: "
        <<kthorder(a, 0, sizeof(a)/sizeof(int)-1, i)
        <<"\n";
    }
    sort(a, a+sizeof(a)/sizeof(int));
}
