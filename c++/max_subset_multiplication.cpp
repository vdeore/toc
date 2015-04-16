#include <iostream>
#include <vector>
using namespace std;

int max_subset_mult(vector<int> v) {
    int pos = 0, neg = 0, max_neg = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > 0) {
            pos = pos ? pos * v[i] : v[i]; 
        } else {
            max_neg = max_neg ? (max_neg < v[i] ? v[i] : max_neg) : v[i];
            neg = neg ? neg * v[i] : v[i]; 
        }
    }
    if (pos && (neg > 0)) {
        return pos * neg;
    }
    if (!pos) {
        if (neg > 0) {
            return neg;
        } else if (max_neg == neg) {
            return neg;
        } else if (neg < 0) {
            return neg/max_neg;
        }
    } else {
        if (neg) {
            return pos*neg/max_neg;
        }
    }
    return pos;
}

main () {
    int a[] = {-1, 0};
    vector<int> v(a, a + sizeof(a)/sizeof(int));
    cout << "\n max subset multi : " << max_subset_mult(v);
}
