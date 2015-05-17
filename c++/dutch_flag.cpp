#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dutch_flag (int a[], int n) {
    int lo = 0, hi = n -1, mid = 0;

    while (mid <= hi)  {
        switch(a[mid]) {
            case 0:
                swap(a[mid++], a[lo++]);
                break;
            case 1:
                ++mid;
                break;
            case 2:
                swap(a[mid], a[hi--]);
                break;
        }
    }
    cout <<"\n";
    for (int i = 0; i < n ; ++i) {
        cout <<" "<<a[i]<<", ";
    }
    cout <<"\n";
    cout <<" count 0: "<<lo;
    cout <<" count 1: "<<hi - lo + 1 ;
    cout <<" count 2: "<<n - hi - 1; 
    cout <<"\n";
}

main () {
    int a[]  = {1,0,1,2,0,1,1,1,2,2};
    dutch_flag(a, sizeof(a)/sizeof(a[0]));
}
