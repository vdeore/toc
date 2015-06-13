/* problem statement: 
 * Given a sorted array, find a way to find the # of occurrence of a number 
 * for eg: [1, 1, 2, 3, 3, 3, 4, 5] 
 * find # of occurrence of 3 in time better than O(n)
 * */

#include <iostream>
using namespace std;

int find(int a[], int l, int r) {
    int m, v = a[l];

    while (1) {
        m = (l + r)/2;
        if (v < a[m]) { r = m; }
        else if (v > a[m]) { l = m; }
        else {
            if (a[m+1] != v) { break; }
            else {
                l = m;
            }
        }
    }
    return m;
}

void find_all_occurences(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        int r = find(a, i, n);
        cout <<"\n"<<a[i]<<" [ "<<i<<" - "<<r<<" ] -> "
             <<r - i + 1;
        i = r;
    }
    cout <<"\n";
}

main () {
    int a[] = {1,1,2,3,3,3,4,5};
    find_all_occurences(a, sizeof(a)/sizeof(int));
}
