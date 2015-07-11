/* SPOJ
 * SBANK - Sorting Bank Accounts
 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct accnt {
    char info[6][16];
    int cnt;
} accnt;

typedef struct node {
    accnt acc;
    node *left, *right;
    node(accnt *a) {
        for (int i = 0; i < 6; ++i) 
            strcpy(acc.info[i], a->info[i]);
        acc.cnt = 1;
        left = right = NULL;
    }
} node;

void print(accnt *a) {
    cout <<"\n";
    for(int j = 0; j < 6; ++j) 
        cout <<a->info[j]<<" ";
    cout <<" "<<a->cnt;
}

void inorder(node *r) {
    if (r) {
        inorder(r->left);
        print(&r->acc);
        inorder(r->right);
    }
}

int comp(accnt *a, accnt *b) {
    for (int i = 0; i < 6; ++i) {
        if (strcmp(a->info[i], b->info[i])) {
            return strcmp(a->info[i], b->info[i]);
        }
    }
    return 0;
}

node* insert(node *r, accnt *a) {
    node *tmp = r, *prev;
    if (!r) {
        return(new node(a));
    }
    while (tmp) {
        prev = tmp;
        if (comp(&tmp->acc, a) > 0) {
            tmp = tmp->left;
        } else if (comp(&tmp->acc, a) < 0) {
            tmp = tmp->right;
        } else {
            tmp->acc.cnt++;
            return r;
        }
    }
    if (!tmp) {
        tmp = new node(a);
        if (comp(&prev->acc, a) > 0) {
            prev->left = tmp;
        } else {
            prev->right = tmp;
        } 
    }
    return r;
}

main () {
    int t, n[5];
    node *r[5] = {NULL};
    cin >> t;
    for (int k = 0; k < t; ++k) {
        cin >> n[k];
        for (int i = 0; i < n[k]; ++i) {
            accnt acc;
            for(int j = 0; j < 6; ++j) {
                cin >> acc.info[j];
            }
            r[k] = insert(r[k], &acc);
        }
    }
    for (int k = 0; k < t; ++k) {
        inorder(r[k]);
        cout <<"\n";
    }
}
