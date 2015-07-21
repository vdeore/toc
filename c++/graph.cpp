/* basic graph implementation
 */

#include <iostream>
#include <list>
#include <queue>

using namespace std;

class graph {
    int v;
    list<int> *adj;

    void DFSUtil(int, bool[]);
    public: 
    graph():v(0),adj(NULL) {}
    graph(int v) {
        this->v = v;
        adj = new list<int>[v];
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    void DFS();
    void BFS(int);
};

void graph::DFSUtil (int i, bool visited[]) {
    visited[i] = true;

    cout <<" "<< i << " ";
    for (list<int>::iterator it = adj[i].begin();
         it != adj[i].end(); ++it) {
        if (!visited[*it]) {
            DFSUtil(*it, visited);
        }
    }
}

void graph::DFS () {
    bool *visited;
    visited = new bool[v];
    for (int i = 0; i < v; ++i) { visited[i] = false; }
    cout <<"\nDFS : ";
    for (int i = 0; i < v; ++i) {
        if (!visited[i]) {
            DFSUtil(i, visited);
        }
    }
    delete visited;
}

void graph::BFS (int s) {
    queue<int> q;
    bool *visited;
    visited = new bool[v];
    for (int i = 0; i < v; ++i) { visited[i] = false; }

    cout <<"\nBFS : ";
    q.push(s);

    while (!q.empty()) {
        int t = q.front(); 
        q.pop();
        cout <<" "<<t;
        visited[t] = true;
        list <int>::iterator it;
        for (it = adj[t].begin(); it != adj[t].end(); ++it) {
            if (!visited[*it]) {
                q.push(*it);
            }
        }
    }
    delete visited;
}

main () {
    graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.DFS();
    g.BFS(2);
}
