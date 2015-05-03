/* 
 * problem :Given a set of intervals, find the maximum no of intervals that are overlapped at the same time.
 * */

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

class activity {
    vector<pair<int, int> > intervals;
    public:
    activity(); 
    activity(int s[], int f[], int n);
    void schedule();
    friend ostream& operator<< (ostream& os, const activity &ii);
};

bool compare(pair<int, int> a, pair<int, int>b) {
    return (a.second < b.second);
}

activity::activity(int s[], int f[], int n) {
    intervals.resize(n);
    for (int i = 0; i < n; i++) {
        intervals[i] = make_pair(s[i], f[i]);
    }
    cout << *this;
}

ostream& operator<< (ostream& os, const activity &ii) {
    os << "\n";
    for (int i = 0; i < ii.intervals.size(); i++) {
        os << "{"<<ii.intervals[i].first<<", "<<ii.intervals[i].second<<"}, ";
    }
    os << "\n";
    return os;
}

void activity::schedule() {
    int i = 0, last_f = -1; 
    
    sort(intervals.begin(), intervals.end(), compare);
    cout << *this;
    cout <<"\nmax-interval schedule:";
    while (i < intervals.size()) {
        if (last_f < intervals[i].first) {
            cout <<" {"<<intervals[i].first<<", "<<intervals[i].second<<"}, ";
            last_f = intervals[i].second;
        }
        ++i;
    }
    cout <<"\n";
}

main () {
    int s[] = {0,5,2,10,6,1,9};
    int f[] = {1,7,4,13,8,6,11};
    activity a(s, f, sizeof(s)/sizeof(int));
    a.schedule();
}
