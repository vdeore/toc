/* Given a sorted array form range [0-99], 
 * convert to string missing elements.
 *
 * e.x.{2,6,8} -> 0-1,3-5,7,9-99
 */

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
#define N 99 

string print_range(int a, int b) {
    string tmp;
    stringstream out, out1;
    int d = b - a -1;
    switch (d) {
        case 0:
            out << b;
            tmp = out.str();
            break;
        case 1:
            out << a+1;
            tmp = out.str()+",";
            break;
        default:
            out << a+1;
            tmp = out.str();
            out1 << b-1;
            tmp += "-" +out1.str()+",";
    }
    return tmp; 
}

string missing(vector<int> a) {
    string res, tmp;
    int i = 0;

    if (a[0]) {
        tmp = print_range(-1, a[0]);
        res += tmp;
    }
    for (i = 0; i < a.size()-1; ++i) {
        int d = a[i+1] - a[i]-1;
        if (d) {
            tmp = print_range(a[i], a[i+1]);
            res += tmp; 
        }
    }
    if (N - a[i]) {
        tmp = print_range(a[i], N+1);
        res += tmp; 
    }
    if (res[res.length()-1] == ',') {
        res[res.length()-1] = '\0';
    }
    return res;
}

main () {
    int a[] = {2,6,8};
    vector<int> v(a, a+sizeof(a)/sizeof(int));
    cout <<"\nMissing elements : "<<missing(v)<<"\n";
}
