#include<iostream>
#include<vector>
#include<string>
using namespace std;

#define N 8
char board[N][N];

void print(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout <<" "<<board[i][j];
        cout <<"\n";
    }
}
void init(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            board[i][j] = '.';
    }
}

bool valid(int x, int y, int n) {
    int tx = x, ty = y;
    for (int i = 0; i < n; ++i) {
        if (board[x][i] == 'Q' || board[i][y] == 'Q') {
            return false;
        }
    }
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 'Q') {
            return false;
        }
        --x, --y;
    }
    x = tx, y = ty;
    while (x < n && y < n) {
        if (board[x][y] == 'Q') {
            return false;
        }
        ++x, ++y;
    }
    x = tx, y = ty;
    while (x >= 0 && y < n) {
        if (board[x][y] == 'Q') {
            return false;
        }
        --x, ++y;
    }
    x = tx, y = ty;
    while (x < n && y >= 0) {
        if (board[x][y] == 'Q') {
            return false;
        }
        ++x, --y;
    }

    return true;
}

bool solve(int q, int n) {
    if (q == n) {
        return true;
    }
    for (int i = 0; i < n; ++i) {
        if (!valid(i, q, n)) {
            continue;
        }
        board[i][q] = 'Q';
        if (!solve(q+1, n)) {
            board[i][q] = '.';
        } else 
            return true;
    }
    return false;
}

main () {
    int q = 8;
    init(q);
    cout <<"\nsolvable ? :  "<<solve(0, q)<<"\n";
    print(q);
}
