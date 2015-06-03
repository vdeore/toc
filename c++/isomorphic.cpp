/* problem statement: 
 * Given two strings s and t, determine if they are isomorphic.
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * All occurrences of a character must be replaced with another character while i
 * preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 */

#include<iostream>
#include<string>
#include<map>
using namespace std;

bool isomorphic(string s, string t) {
    map<char, char> m;
    if (s.length() != t.length()) {
        return false;
    }
    for (int i = 0; i < s.length(); ++i) {
        if (m.find(s[i]) == m.end()) {
            m[s[i]] = t[i];
        } else {
            if (m[s[i]] != t[i]) {
                return false;
            }
        }
    }
    return true;
}

main () {
    string str[3][2] = {{"egg", "add" },
                        {"foo", "bar"},
                        {"paper", "title"}};
    for (int i =0 ; i < 3; ++i) {
        cout <<"\n s: "<<str[i][0]<<" t: "<<str[i][1]
             <<" is_isomorphic : "
             <<isomorphic(str[i][0], str[i][1]);
    }
    cout<<"\n";
}
