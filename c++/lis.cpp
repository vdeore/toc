#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

#define dbg 1

void print_sq(int a[], vector<int>& L, int mx_sq) {
    int indx, val;
    stack<int> st;
    for (int i = 0; i < L.size(); ++i) {
        if (L[i] == mx_sq) {
            indx = i;
            break;
        }
    }

    //cout <<"\nmx_sq : " << mx_sq << " indx: "<<indx;
    while (mx_sq > 0)  {
        int val = a[indx];
        st.push(val);
        mx_sq--;
        for (int j = indx-1; j >=0 ; --j) {
            if (a[j] < val && L[j] == mx_sq) {
                indx = j; 
                break;
            }
        }
    }

    cout <<"\nsolution : ";
    while (!st.empty()) {
        cout << " "<<st.top();
        st.pop();
    }
}

int longest_inc_sq(int a[], int n) {
    vector<int>L(20);
    int mx_sq = -1;

   // L.reserve(n);
    for (int i = 0; i < n; ++i) {
        L[i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i] && L[i] < L[j] + 1) { 
                L[i] = L[j] + 1; 
            }
        }
        mx_sq = max(mx_sq, L[i]);
    }
    cout <<"\nin : {";
    for (int i = 0; i < n; ++i) {
        cout <<a[i]<<", ";
    }
    cout <<"}";
#ifdef dbg
    cout <<"\nL : {";
    for (int i = 0; i < n; ++i) {
        cout <<L[i]<<", ";
    }
#endif
    cout <<"}\n";

    print_sq(a, L, mx_sq);

    return mx_sq;
}

main () {
    int a[] = { 10, 22, 9, 33, 21, 50, 41, 60, 80 };
    int b[] = {3,2,6,4,5,1};
    int c[] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    cout<<"\nlongest incr sq : "
        <<longest_inc_sq(a, sizeof(a)/sizeof(int))<<"\n";
    cout<<"\nlongest incr sq : "
        <<longest_inc_sq(b, sizeof(b)/sizeof(int))<<"\n";
    cout<<"\nlongest incr sq : "
        <<longest_inc_sq(c, sizeof(c)/sizeof(int))<<"\n";
}
