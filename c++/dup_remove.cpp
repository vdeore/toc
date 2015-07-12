#include <iostream>
#include <vector>

using namespace std;

void remove_dup(vector<int> &v) {
    int prev = -999, l = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (prev != v[i]) {
            prev = v[i];
            v[l++] = v[i];
        }
    }
    v.resize(l);
}

main () {
    int a[] = {1,1,1,2,3,4,5,5,6,6};
    vector<int> v(a, a+sizeof(a)/sizeof(int));

    remove_dup(v);
    cout <<"\n";
    for (int i = 0; i < v.size(); ++i) {
        cout <<" "<<v[i];
    }
    cout <<"\n";
}
