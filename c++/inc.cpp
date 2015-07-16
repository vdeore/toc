/* Google phone interview
 * You are given an array representing integer. Write a function which increments this integer.
 * Example: input [1,2,3] (represents 123) -> output [1,2,4]
 * */

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void print(vector<int> &v) {
    cout <<"\n"; 
    for (int i = 0; i < v.size(); ++i) {
        cout <<v[i];
    }
    cout <<"\n"; 
}

void inc(vector<int> &v) {
    int i = v.size()-1, c = 1;
    stack<int> s;

    while (i > -1) {
        v[i] = v[i] + c;
        c = (int)v[i]/10;
        s.push(v[i]%10);
        --i;
    }
    if (c) {
        s.push(c);
    }
    v.empty();
    v.resize(s.size());
    i = 0;
    while(!s.empty()) {
        v[i] = s.top();
        s.pop();
        ++i;
    }
}

main () {
    int a[] = {1};
    vector<int> v(a, a+sizeof(a)/sizeof(int));
    print(v);
    inc(v);
    print(v);
}
