/* problem:
 * Given an array of size n, find the majority element.
 * The majority element is the element that appears more than [ n/2 ] times.
 */
#include <iostream>
#include <algorithm>
using namespace std;

void print(int a[], int n) {
    cout <<"\n";
    for (int i = 0; i < n; ++i) {
        cout <<" "<<a[i];
    }
    cout <<"\n";
}

int partition(int a[], int l, int r) {
    int p; 
    if (l == r) { return l; }
    p = a[(l+r)/2];

    while (l <=r ) {
        while(l >= r && a[l] < p) { ++l; }
        while(l >= r && a[r] > p) { --r; }
        if (l <= r) {
            swap(a[l], a[r]);
            ++l; --r;
        }
    }
    return l;
}

int kthorder(int a[], int l, int r, int k) {
    if (l == r) {
        return a[l];
    }
    int rank = partition(a, l, r);
    if (rank == k-1) {
        return(a[rank]);
    }
    if (rank < k-1) {
        return kthorder(a, rank+1, r, k);
    } 
    return kthorder(a, l, rank-1, k);
}

int majority(int a[], int n) {
    cout <<" rank : "<<n/2;
    return kthorder(a, 0, n-1, (n-1)/2);
}

main () {
    int a[] = {2,3,1,1,1,1,4};
    cout <<"\nMajority element :"
         <<majority(a, sizeof(a)/sizeof(int));
    sort(a, a+sizeof(a)/sizeof(int));
    print(a, sizeof(a)/sizeof(int));
}
