/* problem statement:
   Given a string S and a string T, find the minimum window in S which will 
    contain all the characters in T in complexity O(n).
 * */
#include <iostream>
#include <string>
using namespace std;

//#define dbg 1

string minwindow(string s, string t) {
    int has_found[256] = {0}, count[256] = {0};
    string ans;

    for (int i = 0; i < t.length(); ++i) {
        ++count[t[i]];
    }
#if dbg
    for (int i = 0; i < t.length(); ++i) {
        if (count[t[i]]) {
            cout <<"\ncount["<<(char)t[i]<<"] : "<<count[t[i]];
        }
    }
#endif

    int min_window = 9999, curr_window;
    for (int i = 0, begin = 0, len = 0; i < s.length(); ++i) {
        if (!count[s[i]]) {
            continue;
        }
        if (has_found[s[i]] < count[s[i]]) ++len;
        ++has_found[s[i]];
#if dbg
        cout <<"\nhas_found["<<s[i]<<"] : "<<has_found[s[i]]
             <<" count: ["<<s[i]<<"] : "<<count[s[i]];
#endif
        if (len == t.length()) {
            while(!has_found[s[begin]] ||
                  has_found[s[begin]] > count[s[begin]]) {
                if (has_found[s[begin]] > count[s[begin]]) {
                    --has_found[s[begin]];
                }
                ++begin;
            }
            curr_window = i - begin + 1;
            min_window = min(min_window, curr_window);
            if (min_window == curr_window) {
                ans = s.substr(begin, i);
                cout << "\nans : "<<ans;
            }
        }
    }
    return ans;
}

main () {
string s = "ESADOBECODEBANC";
//string s = "BABBC";
    string t = "ABC";
    cout <<"\nminwindow : "<<minwindow(s, t)<<"\n";
}
