/*
 *
Minimum number of jumps to reach end

Given an array of integers where each element represents the max number of steps 
that can be made forward from that element. Write a function to return the minimum 
number of jumps to reach the end of the array (starting from the first element). 
If an element is 0, then cannot move through that element.

Example:

Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3 (1-> 3 -> 8 ->9)
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minsteps(int a[], int n) {
    vector<int> m;
    m.reserve(100);
    m[0] = 0;
    for (int i = 1; i < n; ++i) {
        m[i] = INT_MAX;
        for (int j = 0; j < i; ++j) {
//          cout <<"\n "<<i<<" "<<j<<" "<<a[j];
            if (i - j <= a[j]) {
                if (j) {
                    m[i] = min(m[i], m[j]+1);
                } else {
                    m[i] = 1;
                }
            }
        }
    }
    return m[n-1];
}

main () {
    int a[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int b[] = {1, 1, 1, 1, 0, 9};
    int c[] = {1, 1, 1, 9}; 
    cout << "\nres a: "<<minsteps(a, sizeof(a)/sizeof(int)) << "\n";
    cout << "\nres b : "<<minsteps(b, sizeof(b)/sizeof(int)) << "\n";
    cout << "\nres c: "<<minsteps(c, sizeof(c)/sizeof(int)) << "\n";
}
