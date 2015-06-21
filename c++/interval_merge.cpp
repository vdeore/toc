/* Porblem: 
 * Merging overlapping intervals
 * */

#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<utility>
#define N 3
using namespace std;
bool compare(pair<int, int>a, pair<int, int>b) {
    return (a.first < b.first);
}

void print(vector<pair<int, int> > &v) {
    cout <<"\n";
    for (int i = 0; i < v.size(); ++i) {
        cout <<" ["<<v[i].first<<", "<<v[i].second<<"]";
    }
    cout <<"\n";
}

void insert(vector<pair<int, int> >&v, pair<int, int> nw) {
    stack<pair<int, int> > s;

    v.insert(v.begin(), nw);
    sort(v.begin(), v.end(), compare);
    print(v);
    s.push(v[0]);

    for (int i = 1; i < v.size(); ++i) {
        pair<int, int> top = s.top();
        if (top.second >= v[i].first) {
            s.pop();
            top.second = max(top.second, v[i].second);;
            s.push(top);
        } else {
            s.push(v[i]);
        }
    }

    v.clear();
    v.resize(v.size());
    while (!s.empty()) {
        pair <int,int>top = s.top();
        v.push_back(top);
        s.pop();
    }
    sort(v.begin(), v.end(), compare);
}

main () {
    int ii[N][2] = {{0,2}, {3,6},  {7,10}};
    vector<pair<int, int> >v;

    v.resize(N);
    for (int i = 0; i < N; ++i) {
        v[i] = make_pair(ii[i][0], ii[i][1]);
    }

    cout <<"\nbefore insert";
    print(v);

    insert(v, make_pair(5, 7));
    cout <<"\nafter insert";
    print(v);
}
