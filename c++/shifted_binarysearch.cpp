#include <iostream>
#include <vector>
using namespace std;

class ShiftedBinarySearch {
    public:
        static int binary_search(int k, vector<int>& v);
};

void print (vector<int>& v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
}

int ShiftedBinarySearch::binary_search(int key, vector<int>& v) {
    int l = 0, m;
    int r = v.size() - 1;
    //cout << "\n l : "<<l <<" r: " <<r;
    while (l < r) {
        m = (l + r)/2;
        if (key > v[m] && key < v[r]) {
            l = m;
        } else if (key == v[m]) {
            cout << "\n Found key: v[" << m << "] ->" << key;
            cout <<"\n";
            return m;
        } else {
            r = m;
        }
    }
    //print(v);
    return -1;
}

main () {
    int k = 9;
    int input[] = {5,6,1,2,3,4};
    //int input[] = {1,2,3,4,5,6};

    vector<int> v(input, input + sizeof(input)/sizeof(int));
    
    cout<<"\nshifted binary search indx : "<< ShiftedBinarySearch::binary_search(k, v);
    cout <<"\n";
}
