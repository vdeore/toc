#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class range_numbers {
    public:
    static void get_range(vector<int>& v) {
       sort(v.begin(), v.end());
       for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
           int l = *it;
           while (*it + 1 == *(it + 1)) {
               it++;
           }
           if (l!=*it) {
               cout << "\n "<<l << "-"<<*it;
           } else {
               cout << "\n "<<l ;
           }
       }
    }
};

main () {
    int a[] = {21,1,2,1098,0, 22, 7,1099}; 
    vector<int> v1 (a, a + sizeof(a) / sizeof(int));

    range_numbers::get_range(v1);
    /*for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
        cout << " " << *it;
    }*/
    cout << "\n ";
}
