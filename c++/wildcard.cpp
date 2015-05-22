/*
Problem statement : 
0 1 ? 
? wildcard for 0 or 1 

"01?" 
010 011 

Example: 
01?0? 
Will produce 
01000 
01100 
01001 
01101
*/

#include<iostream>
#include<string>
using namespace std;

void wildcard(string s) {
    size_t found = s.find_first_of("?");
    if (found == string::npos) {
        cout <<"\n"<<s;
        return;
    }
    s.replace(found, 1, "0");
    wildcard(s);
    s.replace(found, 1, "1");
    wildcard(s);
}

main () {
    string s = "01?0?";
    wildcard(s);
}
