#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

void seq(int n) {
    char tmp[100] = "1";
    for (int i = 0; i < n; ++i) {
        string s(tmp);
        cout <<"\n"<<s;
        memset(tmp, 0, 100);
        int k =0;
        for (int j = 0; j < s.length();) {
            int cnt = 0;
            char ch = s[j];
            while (ch == s[j]) {
                cnt++;
                j++;
            }
            tmp[k++] = (char)(cnt + '0');
            tmp[k++] = ch;
        }
    }
}

main () {
    cout << "\nGoogle Sequence :";
    seq(12);
    cout << "\n";
}
