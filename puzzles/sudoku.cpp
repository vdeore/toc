#include <iostream>
#include <cstring>
using namespace std;

bool check (int (*b)[10]) {
    bool chk[10];
    memset(chk, 0, sizeof(chk));

    //row checking
    for (int i = 1; i <= 9; i++) {
        memset(chk, 0, sizeof(chk));
        for (int j = 1; j <= 9; j++) {
            if (chk[b[i][j]])
                return false;
            else
                chk[b[i][j]] = true;
        }
    }

    //column checking
    for (int i = 1; i <= 9; i++) {
        memset(chk, 0, sizeof(chk));
        for (int j = 1; j <= 9; j++) {
            if (chk[b[j][i]])
                return false;
            else
                chk[b[i][j]] = true;
        }
    }

    //checking 3x3 box
    for (int l = 1; l <= 9; l += 3) {
        for (int i = 1; i <= 9 ; i += 3) {
            memset(chk, 0, sizeof(chk));
            for (int j = l; j <= l+2 ; j++) {
                for (int k = i; k <= i+2 ; k++) {
                    if (chk[b[j][k]])
                        return false;
                    else
                        chk[b[j][k]] = true;
                }
            }
        }
    }

    return true;
}

void print_sudoku (int (*b)[10]) {
    cout << "\n\n";
    for (int k = 1; k < 25; k++)
        cout << "-";
    for (int i = 1 ; i <= 9; i++) {
        cout << "\n";
        for (int j = 1; j <= 9; j++) {
            cout <<" "<< b[i][j];
            if (j%3 == 0) 
                cout << " |";
        }
        if (i%3 == 0) {
            cout << "\n";
            for (int k = 1; k < 25; k++)
                cout << "-";
        }
    }
    cout << "\n\n";
}

bool find_space (int (*b)[10], int& ii, int& jj) {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (!b[i][j]) {
                ii = i;
                jj = j;
                return true;
            }
        }
    }
    
    return false;
}

void get_startbox(int ii, int jj, int &r, int &c) {
    if (ii == 1 || (ii > 1 && ii < 4)) {
        r = 1;
    } else if (ii == 4 || (ii > 4 && ii < 7)) {
        r = 4;
    } else if (ii == 7 || (ii > 7 && ii < 10)) {
        r = 7;
    }

    if (jj == 1 || (jj > 1 && jj < 4)) {
        c = 1;
    } else if (jj == 4 || (jj > 4 && jj < 7)) {
        c = 4;
    } else if (jj == 7 || (jj > 7 && jj < 10)) {
        c = 7;
    }
}

bool is_valid (int (*b)[10], int ii, int jj) {
    bool chk[10];
    int r, c;
    memset(chk, 0, sizeof(chk));

    //row checking
    memset(chk, 0, sizeof(chk));
    for (int i = 1; i <= 9; i++) {
        if (b[ii][i] && chk[b[ii][i]])
            return false;
        else
            chk[b[ii][i]] = true;
    }

    //column checking
    memset(chk, 0, sizeof(chk));
    for (int i = 1; i <= 9; i++) {
        if (b[i][jj] && chk[b[i][jj]])
            return false;
        else
            chk[b[i][jj]] = true;
    }

    get_startbox(ii,jj, r,c);

    //checking 3x3 box
    memset(chk, 0, sizeof(chk));
    for (int j = r; j <= r+2; j++) {
        for (int k = c; k <= c+2 ; k++) {
            if (b[j][k] && chk[b[j][k]])
                return false;
            else
                chk[b[j][k]] = true;
        }
    }

    return true;
}

bool solve (int (*b)[10]) {
    int ii, jj, i;
    static int cnt = 0;

    if (!find_space(b, ii, jj)) {
        return true;
    }
    for (i = 1; i <= 9; i++) {
        b[ii][jj] = i;
        if (is_valid(b, ii, jj)) { 
            if (solve(b)) {
                return true;
            } else {
            b[ii][jj] = 0;
            }
        } else 
            b[ii][jj] = 0;
    }
    return false;
}

main () {
    int a[10][10] =  {
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,3,0,6,0,0,0,0,0,0},
        {-1,0,0,0,0,0,2,0,0,0},
        {-1,0,0,0,0,0,0,0,0,0},
        {-1,0,0,0,0,0,0,0,0,0},
        {-1,0,0,0,0,0,0,1,0,0},
        {-1,0,0,0,0,0,0,0,0,0},
        {-1,0,2,0,0,3,0,0,0,0},
        {-1,0,0,0,0,0,0,0,0,0},
        {-1,0,0,0,0,0,0,0,0,0},
    };
    print_sudoku(a);
    cout << "is solvable:  "<< solve(a);
    print_sudoku(a);
}

