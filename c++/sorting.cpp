#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;

class sorting {
    static void merge(int *a, int l, int m, int r);
    public:
    static void print(int *a, int n);
    static void mergesort(int *a, int l, int r); 
};

void sorting::merge(int *a, int l, int m, int r) {
    int *temp = (int*)malloc(sizeof(int)*(r - l + 1));
    int i = l, j = m+1, k = 0;;
    
    //cout <<"\nl = "<<l<<" r = "<<r<<" m = "<<m;
    while (i <= m && j <= r) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }
    while (i <= m) {
       temp[k++] = a[i++];
    }
    while (j <= r) {
       temp[k++] = a[j++];
    }

    memcpy(a+l, temp, k*sizeof(int));
    //print(a+l, k);

    free(temp);
}

void sorting::mergesort(int *a, int l, int r) {
    if (l == r) {
        return;
    }
    if (l < r) {
        int m = (l + r) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    } 
}

void sorting::print(int *a, int n) {
    cout << "\nNumber of elements : " <<n;
    cout << "\n { ";
    for (int i = 0; i < n; ++i) {
        cout <<" "<<a[i];
        if (i < n - 1) {
            cout << ",";
        }
    }
    cout << " } ";
}

main () {
    int a[] = {4,5,10,7,4,8,9,1};
    //int a[] = {6,1,5};
    int n = sizeof(a)/sizeof(int);
    
    sorting::print(a, n);
    sorting::mergesort(a, 0, n-1);
    sorting::print(a, n);
    cout <<"\n";
}
