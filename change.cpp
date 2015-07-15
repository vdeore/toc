#include<iostream>
#include<vector>
using namespace std;

int change(vector<int> &v, int c) {
    vector<int> m;
    m.resize(100);
    for (int i = 0; i < v.size(); ++i) {
        //m[v[i]] = 1;
    }
    m[0] = 0;
    //m[v[0]] = 1;
    int c1 = 0;
    for (int i = v[0]; i <= c; ++i) { 
        int mn = 9999;
        c1 = 0;
        int cnt = 0;
        for (int j = 0; j < v.size(); ++j) {
            mn = min(mn, m[i-v[j]]+1);
            if (m[i-v[j]] || i == v[j]) {
                ++cnt;
            }
            if(mn == m[i-v[j]]+1) {
                c1+=v[j];
            }
        }
        cout <<"\npossible ways for sum "<<i<<": "<<cnt;
        m[i] = mn;
    }
    if (c1!=c) {
        cout <<"\nsum not possible : " << c;
    }
    cout <<"\n";
    for (int i = 0; i <= c; ++i) {
        //cout <<" "<<m[i];
    }
    cout <<"\nmin coin to change "<<c<<" -> "<<m[c]<<"\n";
    return m[c];
}

main () {
    int a[] = {1,2,3};
    //int a[] = {2,3, 5, 6};
    vector<int> v(a, a+sizeof(a)/sizeof(int));
    change(v, 4);
}
