#include <iostream>
#include <vector>
using namespace std;
class heap {
    vector<int> hp;

    void build_heap();
    void heapify_recur(int);
    void heapify_iter(int);
    int left(int i) { return 2*i + 1;}
    int right(int i) { return 2*i + 2;}
    int parent(int i) { 
        if (i%2) {
            return i/2;
        }
        return (i/2-1);
    }
    public:
    heap() {}
    heap(int sz, int a[]) {
        cout <<"Heap size" <<sz;
        hp.reserve(sz);
        for (int i = 0; i < sz; ++i) {
            hp.push_back(a[i]);
        }
        cout <<"Heap size" <<hp.size();
        build_heap();
    }
    void print();
};

void heap::heapify_iter(int i) {
    int l, r, min;

    while(min != i) {
        min = i;
        l = left(i);
        r = right(i);
        if (l <= hp.size() && hp[l] < hp[i]) {
            min = l;
        } else if (r <= hp.size() && hp[r] < hp[i]) {
            min = r;
        }
        if (min != i) {
            swap(hp[i], hp[min]);
            i = parent(i);
        }
    }
}

void heap::heapify_recur(int i) {
    int l = left(i);
    int r = right(i);
    int min = i;

    if (l <= hp.size() && hp[l] < hp[i]) {
        min = l;
    } else if (r <= hp.size() && hp[r] < hp[i]) {
        min = r;
    }
    if (min != i) {
        swap(hp[i], hp[min]);
        heapify_recur(parent(i));
    }
}

void heap::build_heap() {
    for (int i = 0; i < hp.size()/2 ; ++i) {
        //heapify_recur(i);
        heapify_iter(i);
    }
}

void heap::print() {
    cout <<"\n";
    for (int i = 0; i < hp.size(); ++i) {
        cout << " " <<hp[i];
    }
    cout <<"\n";
}


main () {
    int a[] = {8,2,4,4,3,6,5,0};
    heap h(sizeof(a)/sizeof(int), a);

    h.print();
}
