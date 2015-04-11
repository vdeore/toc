/*
 1.  find pair of numbers in array that add to given sum.
 2.  find pair of numbers in array whose sum is closest to 0.
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

class pairsum {
    public:
        static void pair(vector<int>& v, int sum);
        static int pair_sum_close_tozero(vector<int>& v);
};

int pairsum::pair_sum_close_tozero(vector<int>& v) {
    int l = 0, r = v.size() - 1;
    int dsum = 9999;
    sort(v.begin(), v.end());

    while (l < r) {
        int sum = v[l] + v[r];
        if (abs(sum) < dsum) {
            dsum = sum;
        }
        if (sum < 0) {
            l++;
        } else if (sum > 0) {
            r--;
        } else {
            break;
        }
    }

    cout << "\n sum closest to 0: "<<dsum<<"\n";
    return dsum;
}

void pairsum::pair(vector<int>& v, int sum) {
    map<int, bool> m;

    for (int i = 0; i < v.size(); ++i) {
        m[v[i]] = false;
        if (m[sum - v[i]]) {
            cout<<"\n"<<v[i]<<" + "<<sum-v[i] <<" = "<<sum;
        }
        m[v[i]] = true;
    }
    cout<<"\n";
}

main () {
    int a[] = {2,3,7,0,1,8};
    //int a[] = {10, -9, 5, 9, 0, -10, 2, 10, -1, 9};
    vector<int> v(a, a + sizeof(a)/sizeof(int));
    pairsum::pair(v, 10);
    pairsum::pair_sum_close_tozero(v);
}

