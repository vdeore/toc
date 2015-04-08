/*
   find pair of numbers in array that add to given sum.
 */
#include<iostream>
#include<vector>
#include<map>
using namespace std;

class pairsum {
    public:
        static void pair(vector<int>& v, int sum);
};

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
    //int a[] = {2,3,7,0,1,8};
    int a[] = {10, -9, 5, 9, 0, -10, 2, 10, -1, 9};
    vector<int> v(a, a + sizeof(a)/sizeof(int));
    pairsum::pair(v, -10);
}

