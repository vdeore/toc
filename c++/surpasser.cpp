/*The "surpasser" of an element in an array is defined as the number of elements that are to the "right" and bigger than itself.
 *
 * Example:
 * Array:
 * [2, 7, 5, 5, 2, 7, 0, 8, 1]
 * The "surpassers" are
 * [5, 1, 2, 2, 2, 1, 2, 0, 0]
 *
 * Question: Find the maximum surpasser of the array.
 *
 * In this example, maximum surpasser = 5
 */

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct node {
    int v, cnt;
    int rightcnt;
    int surpasser;
    node *left, *right;
    node(int n):v(n),cnt(1),rightcnt(0),surpasser(0),left(NULL),right(NULL){}
} node;

void print(node *r, int &mx) {
    if (r) {
        mx = max(mx, r->surpasser);
        print(r->left, mx);
        cout <<" "<<r->v<<"("<<r->surpasser<<")("<<r->rightcnt<<")"; 
        print(r->right, mx);
    }
}

node* insert(node *r, int v) {
    node *tmp = r;
    node *t = new node(v), *prev = NULL;
    while (tmp) {
        prev = tmp;
        if (tmp->v > v) {
            t->surpasser += tmp->rightcnt + tmp->cnt;
            tmp = tmp->left;
        } else if (tmp->v < v) {
            tmp->rightcnt++;
            tmp= tmp->right;
        } else {
            tmp->surpasser = t->surpasser + tmp->rightcnt;
            tmp->cnt++;
            delete t;
            return r;
        }
    }
    if (!prev) {
        return t;
    }
    if (prev->v > v) {
        prev->left = t;
    } else {
        prev->right = t;
    }
    return r;
}

int count_surpasser(int a[], int n) {
    node *r = NULL;
    for (int i = n-1; i >= 0; --i) {
        r = insert(r, a[i]);
    }
    int mx = 0;
    print(r, mx);
    cout <<"\nmax surpasser: "<<mx<<"\n";
    return mx;
}

main () {
    //int a[] = {82,74,17,93,96,20,25,55,15,24,56};
    int a[]= {2, 7, 5, 5, 2, 7, 0, 8, 1};

    count_surpasser(a, sizeof(a)/sizeof(int));
}
