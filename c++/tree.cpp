#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

#define M 32
#define N 140
#define scale_factor 2
#define root_sep 1

char grid[64][140];
class tree {
    private:
    class node {
        public :
        int v;
        node *left, *right;
        node():v(0),left(NULL),right(NULL) {}
        node(int n):v(n),left(NULL),right(NULL) {}
    };
    node *root;

    void inorder(node*);
    void preorder(node*);
    void postorder(node*);
    int getHeight(node*);
    int putnode(node*, int, int, int, int,
                 queue<pair<int, int> >&,
                 queue<pair<int, int> >&);
    public:
    tree():root(NULL) {}
    tree(vector<int>&);
    node* getroot() { return root;}
    void print();
    void printLevel();
    void prettyprint();
    int height();
    node* ConstructTree(vector<int>&, int, int);
    void print_paths(node *, queue<int>);
    void range(node *, int, int);
    int find_closest(node *, int);
};

int tree::find_closest(node *r, int n) {
    node *tmp = r, *res = r;
    int d, md = 99999;

    while (tmp) {
        d = n - tmp->v; 
        md = min(md, abs(d));
        cout <<"\n "<<d<<" "<<md;
        if (md == abs(d)) {
            res = tmp;
        }
        if (d > 0) {
            tmp = tmp->right;
        } else if (d < 0) {
            tmp = tmp->left;
        } else {
            return tmp->v;
        }
    }
    return res->v;
}

int tree::getHeight(node *r) {
    if (!r) {
        return 0;
    }
    return (max(getHeight(r->left), getHeight(r->right) + 1));
}

int tree::height() {
    int h = getHeight(root);
    cout << "\nHeight of Tree:" <<h<<"\n";
    return h;
}

tree::tree(vector<int>& v) {
    cout <<"constructing tree from vector";
    root = ConstructTree(v, 0, v.size());
}

struct tree::node* tree::ConstructTree(vector<int>& v, int l, int r) {
    node* rt = NULL;
    int m = (l + r)/2;
    if (l < r) {
        rt = new node();
        rt->v = v[m];
        rt->left = ConstructTree(v, l, m);
        rt->right = ConstructTree(v, m+1, r);
    }

    return rt;
}

void tree::inorder(tree::node *r) {
    if (r) {
        inorder(r->left);
        cout << " "<<r->v;
        inorder(r->right);
    }
}

void tree::preorder(tree::node *r) {
    if (r) {
        cout << " "<<r->v;
        preorder(r->left);
        preorder(r->right);
    }
}

void tree::postorder(tree::node *r) {
    if (r) {
        postorder(r->left);
        postorder(r->right);
        cout << " "<<r->v;
    }
}

void tree::print() {
    if (!root) {
        cout <<"\nEmpty tree\n";
    } else {
        cout << "\nInorder Traversal: ";
        inorder(root);
        cout << "\nProrder Traversal: ";
        preorder(root);
        cout << "\nPostorder Traversal: ";
        postorder(root);
        cout << "\n";
    }
}

void tree::printLevel() {
    queue<node *> curr_level, nxt_level;
    node *t = root;
    cout << "\nTree print by Level : ";
    if (!t) {
        return;
    }
    curr_level.push(t);
    while (!curr_level.empty()) {
        t = curr_level.front();
        cout <<" "<<t->v;
        curr_level.pop();
        if (t->left) {
            curr_level.push(t->left);
        }
        if (t->right) {
            curr_level.push(t->right);
        }
    }
    cout << "\n";
}

int putdigits(int t, int x, int y) {
    int d = 1, r = 10, n = t;
    vector<int> v;

    do {
        int nd = n % 10;
        n = n/10;
        v.push_back(nd);
    }while(n);
    for (int i = v.size() -1, j = 0; i >= 0; ++j,--i) {
        grid[x][y+j] = v[i] + '0';
    }
    return d;
}

int tree::putnode(node*n, int x, int y, int lvl, int h,
                 queue<pair<int, int> >& curr_loc_q,
                 queue<pair<int, int> >& nxt_loc_q)
{
    pair<int, int> coord;
    if (!n) { return 0; }
    if (!x) {
        putdigits(n->v, x, y);
    } else {
        coord = curr_loc_q.front();
        curr_loc_q.pop();
        x = coord.first;
        y = coord.second;
    }

    if (n->left) {
        int i;
        if (!x) {
            y= y - 2*h*root_sep;
        }
        for (i = 1; i <= scale_factor *(h - lvl); ++i) {
           grid[x+i][y-i] = (grid[x+i][y-i] == ' ') ?
                            '/' : grid[x+i][y-i];
        }
        if (grid[x+i][y-i] != ' ') {
            putdigits(n->left->v, x+i, y -(i-1)-1);
            nxt_loc_q.push(make_pair(x+i,y-(i-1)-1));
        } else {
            putdigits(n->left->v, x+i, y -i);
            nxt_loc_q.push(make_pair(x+i,y-i));
        }
    }
    if (n->right) {
        int i;
        if (!x) {
            y += 4*h*root_sep;
        }
        for (i = 1; i <= scale_factor *(h - lvl); ++i) {
        grid[x+i][y+i] = (grid[x+i][y+i] == ' ') ?
                          '\\' : grid[x+i][y+i];
        }
        if (grid[x+i][y+i] != ' ') {
            putdigits(n->right->v, x+i, y+i);
            nxt_loc_q.push(make_pair(x+i,y+i));
        } else {
            putdigits(n->right->v, x+i, y+i);
            nxt_loc_q.push(make_pair(x+i,y+i));
        }
    }
    return x;
}

void grid_print(int n) {
    cout <<"x: "<<n;
    for (int i = 0; i < 36; ++i) {
        cout <<"\n";
        for (int j = 0; j < 140; ++j)
            cout <<grid[i][j];
    }
    cout <<"\n";
}

void tree::prettyprint() {
    queue<node *> curr_level, nxt_level;
    queue<pair<int, int> > curr_loc_q, nxt_loc_q;
    node *t = root;
    int h = height();
    int lvl = 0, x = 0, y = 50, lx ;
    if (!t) {
        return;
    }
    curr_level.push(t);
    while (!curr_level.empty()) {
        t = curr_level.front();
        lx = putnode(t, x, y, lvl, h,curr_loc_q, nxt_loc_q);
        curr_level.pop();
        if (t->left) {
            nxt_level.push(t->left);
        }
        if (t->right) {
            nxt_level.push(t->right);
        }
        if (curr_level.empty()) {
            x += h-lvl+1;
            swap(curr_level, nxt_level);
            swap(curr_loc_q, nxt_loc_q);
            ++lvl;
        }
    }
    cout << "\n";
    grid_print(lx);
}

void tree::print_paths(node *r, queue<int> path_q) {
    if (!r) { return; }
    if (r && !r->left && !r->right) {
        cout <<"\n "<<r->v<<"-> ";
        while (!path_q.empty()) {
            path_q.front();
            cout <<" "<< path_q.front();
            path_q.pop();
        }
        return;
    }
    path_q.push(r->v);
    print_paths(r->left, path_q);
    print_paths(r->right, path_q);
}

/* Time complexity O(n), can it be improved ?
 * */
void tree::range(node *r, int x, int y) {
    if (!r) { return; }
    if (x < r->v) {
        range(r->left, x, y);
    } 
    if (y > r->v) {
        range(r->right, x, y);
    } 
    if (r->v >= x && r->v <= y) {
        cout <<" "<<r->v;
    }
}

main () {
    int a[30];
    for (int i = 0; i < 30; ++i) {
        a[i] = i*i;
    }
    vector<int> v(a, a + sizeof(a)/sizeof(int));
    memset(grid, ' ', 32*140);
    tree t1, t2(v);
    t2.print();
    t2.printLevel();
    t2.height();
    t2.prettyprint();
    queue<int> q1;
    t2.print_paths(t2.getroot(), q1);
    cout <<"\n range: ";
    t2.range(t2.getroot(), 2, 5);
    cout <<"\n Find_closest:  "
         <<t2.find_closest(t2.getroot(), 222)<<"\n";
}
