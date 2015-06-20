#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#define N 3
using namespace std;
bool compare(pair<int, int>a, pair<int, int>b) {
    return (a.first < b.second);
}

void print(vector<pair<int, int> > &v) {
    cout <<"\n";
    for (int i = 0; i < v.size(); ++i) {
        cout <<" ["<<v[i].first<<", "<<v[i].second<<"]";
    }
    cout <<"\n";
}

void add(vector<pair<int, int> >&v, int l, int r, pair<int, int> &nw) {
    if (l >= 0 && v[l].first <= nw.second) {
        v[l].first = min(nw.first, v[l].first);
        v[l].second = max(nw.second, v[l].second);
    } else if (l >=0 && v[l].first > nw.second) {
        v.insert(v.begin(), nw);
    } else if (r < v.size() && v[r].second >= nw.first) {
        v[r].first = min(nw.first, v[r].first);
        v[r].second = max(nw.second, v[r].second);
        return;
    } else if (v[r].second > nw.first) {
        v.insert(v.end(), nw);
        return;
    }
}

void insert(vector<pair<int, int> >&v, pair<int, int> nw) {
    int l = 0, r = v.size(), m;

    while (l < r) {
        m = (l+r)/2;
        if (r-l == 1) {
            cout <<"found";
            cout <<"\n* ["<<v[l].first<<", "<<v[l].second<<"]";
            cout <<"\n* ["<<v[r].first<<", "<<v[r].second<<"]\n";
            add(v, l, r, nw);
            break;
        } 
        if (v[m].first < nw.first) {
            l = m;
        } else if (v[m].first > nw.first){
            r = m;
        } else {
            if (v[m].second < nw.second) {
                v[m].second = nw.second;
            }
        }
    }
}

main () {
    int ii[N][2] = {{0,2}, {-10,-1},  {4,10}};
    vector<pair<int, int> >v;

    v.resize(N);
    for (int i = 0; i < N; ++i) {
        v[i] = make_pair(ii[i][0], ii[i][1]);
    }

    print(v);
    cout <<"\nafter sort";
    sort(v.begin(), v.begin()+N, compare);
    print(v);

    insert(v, make_pair(11, 12));
    print(v);
}
