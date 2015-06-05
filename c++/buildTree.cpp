/* Linkedin interview question
 * Given a list of child->parent relationships, build a binary tree out of it. 
 * All the element Ids inside the tree are unique. 
 * Example: 
 *
 * Given the following relationships: 
 *
 * Child Parent IsLeft 
 * 15 20 true 
 * 19 80 true 
 * 17 20 false 
 * 16 80 false 
 * 80 50 false 
 * 50 null false 
 * 20 50 true 
 *
 * You should return the following tree: 
 *     50 
 *    / \ 
 *   20 80 
 *  / \ / \ 
 * 15 17 19 16 
 *
 */
#include<iostream>
#include<map>
#include<list>

using namespace std;
typedef struct Relations {
    int c;
    int p;
    bool left;
} Relations;

typedef struct Node {
    int n;
    struct Node *l;
    struct Node *r;
} Node;

void print(Node *r) {
    if (r) {
        print(r->l);
        cout <<" "<< r->n;
        print(r->r);
    }
}

Node* buildTree(list<Relations>& data) {
    Node *parent, *child, *root = NULL, *t;
    map <int, Node*> m;
    for (list<Relations>::iterator it = data.begin(); 
        it != data.end(); ++it) {
        cout <<"\n "<<it->p<<" "<<it->c<<" "<<it->left;
        parent = child = NULL;
        if (it->p) {
            if (m.find(it->p) == m.end()) {
                parent = new Node();
                parent->n = it->p; parent->l = parent->r = NULL;
                m[parent->n] = parent;
            } else {
                parent = m[it->p];
            }
        }
        if (m.find(it->c) == m.end()) {
            child = new Node();
            child->n = it->c; child->l = child->r = NULL;
            m[child->n] = child;
        } else {
            child = m[it->c];
        }
        if (!parent) {
            root = child;
        } else if (it->left) {
            parent->l = child;
        } else {
            parent->r = child;
        }
    }
    return root;
}

main () {
    list<Relations> data;
    Node *r = NULL;
    Relations rel[] = { {15, 20, true }, 
                        {19, 80, true },
                        {17, 20, false }, 
                        {16, 80, false }, 
                        {80, 50, false }, 
                        {50, 0, false }, 
                        {20, 50, true } };

    for (int i = 0; i < 7; ++i) {
        data.push_back(rel[i]);
    }
    r = buildTree(data);
    cout <<"\n Tree Traversal: ";
    print(r);
    cout <<"\n";
}
