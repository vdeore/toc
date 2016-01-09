#include<iostream>
#include<vector>
using namespace std;

int jump(vector<int>& a) {
    int i = 0, steps = 0, current_reach = i+a[i], next_reach = 0;
    while (i < a.size()) {
        next_reach = 0;
        cout <<"\njumping to "<<current_reach;
        for (; i <= current_reach; ++i) {
            next_reach = max(next_reach, i + a[i]);
        }
        current_reach = next_reach;
        steps++;
    }
    return steps;
}

main () {
    int a[] = {2,3,1,1,4};
    vector<int> v(a, a+sizeof(a)/sizeof(int));

    cout <<"\n "<<jump(v);
}
