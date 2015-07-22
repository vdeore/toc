/* Amazon interview question:
Given a matrix containing 0 and 1. Consider 1 as 'Land' and 0 as 'Water'.i
Find out the number of 'Islands' in the matrix. That is, set of all adjacent 1 
will make up for an island. 

For example: 

[ 0 1 1 0 1 ] 
[ 1 1 1 0 0 ] 
[ 0 0 0 1 1 ] 
[ 1 0 0 1 0 ] 

This problem has 4 islands. ( consider set of 1s, vertically, horizontally and
diagonally ).
*/
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <queue>
using namespace std;
#define N 5

void 
qneightbors(pair<int,int> p, queue<pair<int,int> > &q) 
{
    q.push(make_pair(p.first+1, p.second));
    q.push(make_pair(p.first-1, p.second));
    q.push(make_pair(p.first, p.second+1));
    q.push(make_pair(p.first, p.second-1));
}

void BFSUtil(int a[][N], pair<int, int> p, map<pair<int,int>,bool> &visited)
{
    queue<pair<int,int> > q;
    q.push(p);
    while(!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        if (!visited[t] && t.first >=0 && t.first < N
            && t.second >=0 && t.second < N && a[t.first][t.second]) {
            cout <<"\n("<<t.first<<", "<<t.second<<")";
            visited[t] = true;
            qneightbors(t, q);
        }
    }
}

int BFS(int a[][N]) {
    map<pair<int,int>, bool> visited;
    int count = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            visited[make_pair(i, j)] = false;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (a[i][j] && !visited[make_pair(i, j)]) {
                count++;
                cout <<"\n\n";
                BFSUtil(a, make_pair(i, j), visited);
            }
        }
    }
    return count;
}

main () {
    int a[N][N] = {{1,0,0,0,1},
                   {0,0,1,0,0},    
                   {0,0,0,0,0},    
                   {1,0,1,0,1}};
    cout <<"\n#of islands : "<< BFS(a) <<"\n";
}
