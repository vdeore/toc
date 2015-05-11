/* problem 1:
 * Given a number n, find the smallest number that has same set of digits as n and is greater than n. 
 * If x is the greatest possible number with its set of digits, then print “not possible”.
 *
 * Examples:
 * Input:  n = "218765"
 * Output: "251678"
 *
 * Input:  n = "1234"
 * Output: "1243"
 *
 * Input: n = "4321"
 * Output: "Not Possible"
 *
 * Input: n = "534976"
 * Output: "536479"
 *
 * problem 2:
 * Find next lexicographically greater string ?
 * Sample Input
 *
 * ab
 * bb
 * hefg
 * dhck
 * dkhc
 * Sample Output
 *
 * ba
 * no answer
 * hegf
 * dhkc
 * hcdk
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

#define dbg

bool comp (int x, int y) { return (x > y); }

int next_greater(int n) {
    vector <int> v(5);
    int t = n, num_digits = 0, indx_a , a;
    bool done;

    while (t) {
        v[num_digits++] = t%10; t = t/10;
    }
    done = false;
    for (int i = 0; i < num_digits-1; ++i) {
        if (v[i] > v[i+1]) {
            done = true;
            a = v[i+1];
            indx_a = i+1;
            break;
        }
    }
    if (!done) {
        cout <<"\n no solution";
        return -1;
    }
#ifdef dbg 
    for (int i = 0; i < num_digits; ++i) {
        cout <<"\n v["<<i<<"] -> "<<v[i];
    }
#endif
    int smallest = 9999, indx_grtr_aftr_a;
    for (int l=0; l < num_digits; ++l) {
        if (a<v[l] && smallest > v[l]) {
            smallest = v[l];
            indx_grtr_aftr_a = l;
        }
    }
#ifdef dbg 
    cout <<"\n a "<<a <<" indx_a :"<<indx_a <<" indx_grtr_aftr_a: "<<indx_grtr_aftr_a;
    cout <<"\n smallest :"<<smallest<<" index "<<indx_grtr_aftr_a;
#endif
    swap(v[indx_grtr_aftr_a], v[indx_a]);
#ifdef dbg 
    for (int i = 0; i < num_digits; ++i) {
        cout <<"\n v["<<i<<"] -> "<<v[i];
    }
#endif
    sort(v.begin(), v.begin()+indx_a, comp);
    int num = 0;
    for (int i = 0; i < num_digits; ++i) {
        num += v[i]*pow(10, i);
    }
    return num;

}

string next_greater_str(string in) {
    bool done = false;
    string s(in);
    int indx_a;
    char a;
    int indx_grtr_aftr_a;

    for (int i = s.length()-1; i > 0; --i) {
#ifdef dbg 
        cout <<"\n "<<s[i]<<" "<<(int)s[i]<<" "<<s[i-1]<<" "<<(int)s[i-1];
#endif
        if (s[i] > s[i-1]) {
            done = true;
            a = s[i-1];
            indx_a = i-1;
            break;
        }
    }
    if (!done) { 
        cout <<"\n no solution";
        return;
    }
    char smallest = 120;
    for (int i = indx_a; i <s.length(); ++i) {
        if (a<s[i] && smallest > s[i]) {
            smallest = s[i];
            indx_grtr_aftr_a = i;
        }
    }
#ifdef dbg 
    cout <<"\n a '"<<a <<"' indx_a :"<<indx_a <<" indx_grtr_aftr_a: "<<indx_grtr_aftr_a;
    cout <<" smallest :"<<smallest<<" index "<<indx_grtr_aftr_a;
#endif
    swap(s[indx_grtr_aftr_a], s[indx_a]);
    sort(s.begin()+indx_a+1, s.end());
    return s;
}

main () {
#if 0
    int n;
    n = 7453; 
    cout <<"\nNext greater :" <<n<<"->"<<next_greater(n);
    n = 7534; 
    cout <<"\nNext greater :" <<n<<"->"<<next_greater(n);
    n = 7435; 
    cout <<"\nNext greater :" <<n<<"->"<<next_greater(n);
    n = 2961; 
    cout <<"\nNext greater :" <<n<<"->"<<next_greater(n);
    string s;
#endif
    string s;
    cout <<"\nEnter string : ";
    cin >> s;
    cout <<"\nNext greater str:" <<next_greater_str(s)<<"\n";
}
