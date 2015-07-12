#include <iostream>
#include <vector>
using namespace std;

int peak(vector<int>& a, int l, int r) {
    int m = (l+r)/2, tmp;
    cout << "\n "<<l <<" "<<r<<" "<<m;
    if (l==r) { return l; }
    if (r-l == 1) {
        return a[r] > a[l] ? r : -1;
    }
    if (a[m-1] < a[m] && a[m] > a[m+1]) { 
        return m; 
    }
    tmp = peak(a, m, r);
    if (tmp != -1) { 
        return tmp; 
    }
    tmp = peak(a, l, m);
    if (tmp != -1) { 
        return tmp; 
    }
    return -1; 
}

int findPeakElement(vector<int>& nums) {
    switch (nums.size()) {
        case 2:
            return nums[0] < nums[1] ? 1 : 0;
            break;
        default:
            if (nums[0] > nums[1]) {
                return 0;
            }
            if (nums[nums.size()-1] > nums[nums.size()-2]) {
                return nums.size()-1;
            }
            return peak(nums, 0, nums.size()-1);
    }
    return 0;
}

main () {
    int a[] = {3,2,1,4,3};
    vector<int> v(a, a+sizeof(a)/sizeof(int));
    cout <<"\nPeak : "<< findPeakElement(v);
}
