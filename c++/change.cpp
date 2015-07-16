/* find the number of ways change can be made
 * */

#include<iostream>
#include<vector>
#include<map>
using namespace std;

long change(vector<long> &v, long c) {
    vector<long> m;
    m.reserve(100);
    m[0] = 1;
    for (long i = 0; i < v.size(); ++i) {
        for (long j = v[i]; j <= c; ++j) 
            m[j] += m[j-v[i]];
        cout <<" "<<m[i];
    }

    cout <<"\n possible ways : "<<m[c];
}

main () {
    //long a[] = {1};
    long a[] = {2,5,3,6};
    vector<long> v(a, a+sizeof(a)/sizeof(long));
    change(v, 10);
}
