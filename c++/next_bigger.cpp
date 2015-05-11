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
 * incomplete yet
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

bool comp (int x, int y) { return (x > y); }

int next_bigger(int n) {
    vector <int> v(5);
    int t = n, num_digits = 0, index_a , a;
    bool done;

    while (t) {
        v[num_digits++] = t%10; t = t/10;
    }
    done = false;
    for (int i = 0; i < num_digits-1; ++i) {
        if (v[i] > v[i+1]) {
            done = true;
            a = v[i+1];
            index_a = i+1;
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
    cout <<"\n a "<<a <<" index_a :"<<index_a <<" indx_grtr_aftr_a: "<<indx_grtr_aftr_a;
    cout <<"\n smallest :"<<smallest<<" index "<<indx_grtr_aftr_a;
#endif
    swap(v[indx_grtr_aftr_a], v[index_a]);
#ifdef dbg 
    for (int i = 0; i < num_digits; ++i) {
        cout <<"\n v["<<i<<"] -> "<<v[i];
    }
#endif
    sort(v.begin(), v.begin()+index_a, comp);
    int num = 0;
    for (int i = 0; i < num_digits; ++i) {
        num += v[i]*pow(10, i);
    }
    return num;

}

void next_bigger_str(string &s) {
    bool done = false;
    string buf;
    int indx_a, a;

    int smallest = 9999, indx_grtr_aftr_a;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] > s[i+1]) {
            done = true;
            a = s[i+1];
            indx_a = i+1;
            break;
        }
    }
    for (int i = 0; i < s.length(); ++i) {
        if (a<v[l] && smallest > v[l]) {
            smallest = v[l];
            indx_grtr_aftr_a = l;
            done = true;
        }
    }
    if (!done) { 
        cout <<"\n no solution";
        return;
    }
    sort(s.begin(), s.begin()+index_a, comp);
    cout <<"Greater string <<"<<s;
}

main () {
    int n;
    n = 7453; 
    cout <<"\nNext bigger :" <<n<<"->"<<next_bigger(n);
    n = 7534; 
    cout <<"\nNext bigger :" <<n<<"->"<<next_bigger(n);
    n = 7435; 
    cout <<"\nNext bigger :" <<n<<"->"<<next_bigger(n);
    n = 2961; 
    cout <<"\nNext bigger :" <<n<<"->"<<next_bigger(n);
#if 0
    string s;
    cout <<"\nEnter string : ";
    cin >> s;next_bigger_str(s);
    cout <<"\nNext bigger str:" <<s;
#endif

}

