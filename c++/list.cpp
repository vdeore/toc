#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

template <class T>
class list {
    struct node {
        T data;
        struct node *next;
        node() { data = NULL; next = NULL;}
        node(T v) { data = v; next = NULL;}
    };
    struct node *head;

    public:
    list():head(NULL) {}
    list(const list&);
    ~list();
    void print();
    void rprint(struct node*);
    void recur_print();
    void addFront(T);
    void addEnd(T);
    void delFront();
    void delEnd();
    void reverse();
    bool isSorted();
    void remove_dup();
    void remove_dupSorted();
    void remove_dupUnSorted();
    void del_nxt(struct node *n);
    void pairwise_swap();
    void moveLastToFront();
    void deleteAlternate();
};

template <class T> 
list<T>::list(const list& src) {
}

template <class T>
list<T>::~list() {
    struct node *temp = head, *temp1;
    if (!head) {
        cout << "\n** empty list";
        return;
    }
    temp1 = temp->next;
    while (temp1) {
        delete temp;
        temp = temp1;
        temp1 = temp->next;
    }
}

template <class T>
void list<T>::print() {
    struct node *temp = head;
    if (!head) {
        cout << "\nempty list\n";
        return;
    }
    cout << "\n";
    while (temp) {
        cout<< temp->data;
        temp = temp->next;
        if (temp) {
            cout<< "->";
        }
    }
    cout << "\n";
}

template <class T>
void list<T>::rprint(struct node *n) {
    if (!n) {
        return;
    }
    rprint(n->next);
    cout << n->data << "<-"; 
}

template <class T>
void list<T>::recur_print() {
    rprint(head);
}

template <class T>
void list<T>::addEnd(T val) {
    struct node *n = new node(val);
    struct node *temp = head;
    if (!temp) {
        head = n;
    } else {
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = n;
    }
}

template <class T>
void list<T>::addFront(T val) {
    struct node *n = new node(val);
    if (head) {
        n->next = head;
    }
    head = n;
}

template <class T>
void list<T>::delFront() {
    struct node *temp = head;
    if (!head) {
        return;
    }
    temp = head; 
    head = head->next;
    delete temp;
}

template <class T>
void list<T>::delEnd() {
    struct node *curr = head, *prev = NULL;
    if (!head) {
        return;
    }
    if (!head->next) {
        curr = head->next;
        head = NULL;
        delete curr;
        return;
    }
    while(curr->next) {
        prev = curr; 
        curr = curr->next;
    }
    curr = prev->next;
    prev->next = NULL;
    delete curr;
}

template <class T>
void list<T>::reverse() {
    struct node *nxt, *prev, *curr;
    if (!head) {
        return;
    }
    prev = NULL;
    curr = head;
    while (curr) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
    cout << "\nreversed list : ";
    print();
}

template <class T>
void list<T>::del_nxt(struct node *n) {
    struct node *temp = n->next;
    cout << "\n deleting " << temp->data;
    n->next = temp->next;
    delete temp;
}

/* remove dup from sorted list*/
template <class T>
void list<T>::remove_dup() {
    if (isSorted()) {
        remove_dupSorted();
    } else {
        remove_dupUnSorted();
    }
}

template <class T>
void list<T>::remove_dupSorted() {
    struct node *curr = head, *nxt = NULL;
    while (curr) {
        nxt = curr->next;
        while (nxt && (curr->data == nxt->data)) {
            del_nxt(curr);
            nxt = curr->next;
        }
        curr = curr->next;
    }
}

template <class T>
void list<T>::remove_dupUnSorted() {
    struct node *curr = head, *nxt = NULL, *curr1 = NULL, *prev = NULL;
    while (curr) {
        curr1 = curr->next;
        prev = curr;
        while (curr1) {
            if (curr1->data == curr->data) {
                del_nxt(prev);
                curr1 = prev->next;
            } else {
                prev = curr1;
                curr1 = curr1->next;
            }
        }
        print();
        curr = curr->next;
    }
}

template <class T>
bool list<T>::isSorted() {
    struct node *curr = head;
    int min = curr->data;
    
    while(curr) {
        cout << "\n " <<min<< " "<<curr->data;
        if (min > curr->data) {
            return false;
        } 
        min = curr->data;
        curr = curr->next;
    }
    return true;
}

template <class T>
void list<T>::pairwise_swap() {
    struct node *temp1 = head, *temp2 = temp1->next, *nxt, *prev = NULL;

    while (temp1 && temp2) {
        nxt = temp2->next;
        temp2->next = temp1;
        temp1->next = nxt;
        if (prev) {
            prev->next = temp2;
        } else {
            head = temp2 ? temp2 : head;
        }
        prev = temp1;
        temp1 = nxt;
        temp2 = temp1 ? temp1->next : NULL;
    }
}

template <class T>
void list<T>::moveLastToFront() {
    struct node *prev = head, *last = prev->next; 
    while (last->next) {
        prev = last;
        last = prev->next;
    }
    last = prev->next;
    prev->next = NULL;

    last->next = head;
    head = last;
}

template <class T>
void list<T>::deleteAlternate() {
    struct node *prev = head;
    while (prev->next) {
        del_nxt(prev);
        prev = prev->next;
    }
}

#define N 2

main () {
    int input[10] = {1,2,2,2,3,5,4,1,5,1};
    //int input[N] = {1,2,2,2,3,3,4,5,5,5};
    list<int> l1;
    srand (time(NULL));

    for (int i = 1; i <= N; i++) {
        l1.addEnd(i);
    }
    l1.print();
   // l1.deleteAlternate();
   l1.pairwise_swap(); 
   l1.print();
}
