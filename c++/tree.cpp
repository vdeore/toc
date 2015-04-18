#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class tree {
    private: 
    class node {
        public : 
        int v;
        node *left, *right;
        node():v(0),left(NULL),right(NULL) {}
        node(int n):v(n),left(NULL),right(NULL) {}
    };
    struct node *root;

    void inorder(node*);
    void preorder(node*);
    void postorder(node*);
    public: 
    tree():root(NULL) {}
    tree(vector<int>&);
    void print();
    void printLevel();
    node* ConstructTree(vector<int>&, int, int);
};

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
        inorder(r->left);
        inorder(r->right);
    }
}
void tree::postorder(tree::node *r) {
    if (r) {
        inorder(r->left);
        inorder(r->right);
        cout << " "<<r->v;
    }
}

void tree::print() {
    if (!root) {
        cout <<"\nEmpty tree\n";
    } else {
        cout << "\nInorder Traversal: \n";
        inorder(root);
        cout << "\nProrder Traversal: \n";
        preorder(root);
        cout << "\nPostorder Traversal: \n";
        postorder(root);
        cout << "\n";
    }
}

void tree::printLevel() {
    queue<node *> curr_level;
    node *t = root;
    cout << "\nTree print by Level : \n";
    if (!t) {
        return;
    }
    curr_level.push(t);
    while (!curr_level.empty()) {
        t = curr_level.front();
        cout << " " <<t->v;
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

main () {
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> v(a, a + sizeof(a)/sizeof(int));
    tree t1, t2(v);
    t2.print();
    t2.printLevel();
}
