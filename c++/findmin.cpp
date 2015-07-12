#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int>& a) {
    int l = 0, r = a.size()-1, m;
    switch(a.size()) {
        case 1:
            return a[0];
        case 2:
            return min(a[0], a[1]);
    }
    while (l < r) {
        m = (l+r)/2;
        if (r-l == 1) {
            return min(a[l], a[r]);
        }
        cout <<"\n"<<l<<" "<<r<<" "<<m;
        if (a[m-1] > a[m]
            && a[m+1] > a[m]) {
            return a[m];
        }
        if (a[m] > a[r]) {
            l = m;
        } else if (a[m] < a[l]) {
            r = m;
        } else {
            return a[l];
        }
    }
    return -1;
}

main () {
    int a[] = {2,3,1};
    vector<int> v(a, a+sizeof(a)/sizeof(int));
    cout <<"\n min : "<<findMin(v);
}


