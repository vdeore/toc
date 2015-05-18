#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//#define dbg 1


main () {
#if dbg
    int n = 3, nk = 3;
    int k[3][3] = {{1,4,1},
                   {2,2,2}, 
                   {2,0,1},
    };
    int c[5][5] = {0};
#else
    int n, nk;
    int k[11][21]; 
    int c[21][11] = {0};

    cin >> n;
    cin >> nk;

    for (int i = 0; i < nk; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >>k[i][j];
        }
    }

#endif

    for (int i = 0; i < nk; ++i) {
        c[0][i] = k[i][0];
    }
    for (int i = 1; i < n; ++i) {
        c[i][0] += c[i-1][0] + k[0][i];
    }
#if dbg
    for (int i = 0; i < n; ++i) {
        cout <<"\n c["<<i<<"] : ";
        for (int j = 0; j < nk; ++j) {
            //cout <<" c["<<i<<"]["<<j<<"] : "<<c[i][j];
            cout <<" "<<c[i][j];
        }
    }
        cout <<"\n";
        cout <<"\n";
#endif
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < nk; ++j) {
            c[i][j] = min(c[i-1][j-1], c[i-1][j]) + k[j][i];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout <<"\n c["<<i<<"] : ";
        for (int j = 0; j < nk; ++j) {
            //cout <<" c["<<i<<"]["<<j<<"] : "<<c[i][j];
            cout <<" "<<c[i][j];
        }
    }
#if dbg
#endif
    int ans = 9999;
    for (int i = 0; i < nk; ++i) {
        ans = min(ans, c[n-1][i]); 
    }
#if dbg
    cout <<"\nmin cost to all gangsters :  "<< ans<<"\n";
#else
    cout <<"\n"<<ans<<"\n";

#endif
}
