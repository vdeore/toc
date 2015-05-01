#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int T[20][20];

int edit_distance(string a, string b) {
    for (int i = 0; i <= a.length(); ++i) {
        T[i][0] = i;
    }
    for (int j = 0; j <= b.length(); ++j) {
        T[0][j] = j;
    }
    for (int i = 1; i <= a.length(); ++i) {
        for (int j = 1; j <= b.length(); ++j) {
            T[i][j] = min(T[i][j-1]+1,
                          min(T[i-1][j]+1,
                              T[i-1][j-1] + abs((int)a[i]-b[j])));
        }
    }
    return T[a.length()][b.length()];
}

main () {
    string a("b"), b("abd");
    cout <<"\nEdit distance :" <<edit_distance(a, b)<<"\n";
}
