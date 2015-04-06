#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

double score(string &s) {
    map <string, int> m;
    int r = 0;
    double score = 0;
    
    cout <<"\n input string: "<< s << "\n";
    for (int i = 0; i < s.length(); ++i) {
        for (r = 1; s[i] == s[i + r -1]; ++r) {
            m[s.substr(i, r)]++;
        }
    }
    for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
        cout << "\n "<< it->first << "->"<< it->second; 
        score += it->second;
    }
    cout << "\n";

    return score;
}

double gift_score(string &s, vector <int> p) {
    int num_q = 0;
    double score = 0.0;
    for (int i =0; i < s.length(); ++i) {
        char ch = '*';
        num_q = 0;
        for (int j = i; j < s.length(); ++j) {
            if (s[j] == '?') {
                num_q++;
            }
            if (ch == '*') {
                if (s[j] != '?') {
                    ch = s[j];
                }
            } else {
                if (s[j] != '?' && s[j] !=ch) {
                    break;
                }
            }
            for (int k = 0; k < p.size(); ++k) {
                if (ch == '*' || k == ch - 'a') {
                    score += pow(p[k]/100, num_q);
                }
            }
        }
    }

    return score;
}

main () {
    string s1("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    int p1[] = {1, 99};
    vector<int> p (p1, p1 + sizeof(p1) / sizeof(int) );
    cout << "\ninput strting :"; 
  
    //cout << "\n " << gift_score(s1, p)<< "\n";
    cout << "\nstring score : "<< score(s1) << "\n";
}
