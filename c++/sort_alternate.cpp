/*
 * given a set of inputs, sort them such that the proceeding digit alternates higher, then lower than the preceding digit 
 * */

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

void sort_alternate (int a[], int n) {
    sort(a, a+n);
    print(a, n);
    for (int i = 2; i < n; i=i+2) {
        swap(a[i-1], a[i]);
    }
}

main () {
    int a[] = {1, 5, 2, 8, 5, 10, 1, 6, 2, 3, 1, 3, 2, 10};
    int n = sizeof(a)/sizeof(int);
    print(a, n);
    sort_alternate(a, n);
    print(a, n);
}
