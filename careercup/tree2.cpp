/* Linkedin Interview Question:
Given a binary tree where all the right nodes are leaf nodes, flip it upside down and turn it into a tree with left leaf nodes. 

Keep in mind: ALL RIGHT NODES IN ORIGINAL TREE ARE LEAF NODE.


 for example, turn these:
 *
 *        1                 1
 *       / \                 / \
 *      2   3            2   3
 *     / \
 *    4   5
 *   / \
 *  6   7
 *
 * into these:
 *
 *        1               1
 *       /               /
 *      2---3         2---3
 *     /
 *    4---5
 *   /
 *  6---7
 *
 * where 6 is the new root node for the left tree, and 2 for the right tree.
 * oriented correctly:
 *
 *     6                   2
 *    / \                   / \
 *   7   4              3   1
 *        / \
 *       5   2
 *            / \
 *          3   1
 */
#include<iostream>
using namespace std;

typedef struct node {
    int v;
    node *left, *right;
    node(int n):v(n),left(NULL),right(NULL) {}
} node;

void inorder(node *r) {
    if (r) {
        inorder(r->left);
        cout <<" "<<r->v;
        inorder(r->right);
    }
}

node* modify(node *r) {
    node *t = r, *prevrt, *rt, *l;
    prevrt = NULL;
    while(t) {
        l = t->left;
        rt = t->right;
        t->right = prevrt;
        prevrt = rt;
        t = l;
    }
    cout <<"\n";
    inorder(r);
    cout <<"\n";
    l = NULL;
    node *pr = NULL, *c = r;
    while (c) {
        l = c->left;
        c->left = pr;
        pr = c;
        c = l;
    }
    cout <<"\n";
    inorder(pr);
    cout <<"\n";
    r = pr;
    while (r) {
        swap(r->left, r->right);
        r = r->right;
    }

    return pr;
}

main () {
    node *r = new node(1);
    r->left = new node(2);
    r->right = new node(3);
    r->left->left = new node(4);
    r->left->right = new node(5);
    r->left->left->left = new node(6);
    r->left->left->right = new node(7);

    cout <<"\nb4 : ";
    inorder(r);
    r = modify(r);
    cout <<"\nafter :";
    cout <<"\n";
    inorder(r);
    cout <<"\n";
}
