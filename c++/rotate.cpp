/* problem statement:
 * Rotate a array by N. N can be smaller of greater than 
 * the array length. 
 * e.g {0,1,2,4,5,6,7} N =4 should return {5,6,7,4,0,1,2}. 
 */

#include<iostream>

using namespace std;

void print(int a[], int n) {
    cout <<"\n";
    for (int i = 0 ; i < n; ++i) {
        cout <<" "<<a[i];
    }
    cout <<"\n";
}

void reverse(int a[], int l, int r) {
    while (l < r) {
        swap(a[l], a[r]);
        l++,r--;
    }
}

void rotate(int a[], int n, int s) {
    s = s % n;
    reverse(a, 0, n-s-1);
    reverse(a, n-s, n-1);
    reverse(a, 0, n-1);
}

main () {
    int a[] = {0,1,2,3,4,5,6,7};

    rotate(a, sizeof(a)/sizeof(int), 2);
    print(a, sizeof(a)/sizeof(int));
}
