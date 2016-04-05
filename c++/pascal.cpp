#include<iostream>
#include<vector>
using namespace std;

void print(vector< vector<int> > v) {
    for (int i = 0 ; i < v.size(); ++i) {
        cout <<"\n";
        for (int j = 0; j < v[i].size(); ++j) {
            cout <<" "<<v[i][j];
        }
    }
        cout <<"\n";
}

vector<vector<int> > generate(int n) {
    vector<vector<int> > v(n);
    for (int i = 0; i < n; ++i) {
        v[i].resize(i+1);
        for (int j = 0; j < i+1; ++j) {
            if (j <= 0 || j >= i) {
                v[i][j] = 1;
            } else {
                v[i][j] = v[i-1][j-1]+ v[i-1][j];
            }
        }
    }
    return v;
}

main () {
    vector<vector<int> > v;
    v = generate(20);
    print(v);
}
