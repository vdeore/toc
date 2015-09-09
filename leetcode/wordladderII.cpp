#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_set>
using namespace std;


vector<string>
Neighbors(string s, unordered_set<string> dict) {
    vector<string> v;
    cout <<"\n Neighbors of "<<s<<" : ";
    for (int i = 0; i < s.size(); ++i) {
        char ch = s[i];
        for(int j = 0; j < 26; ++j) {
            if (ch == 'a'+j) continue;
            s[i] = 'a'+j;
            if (dict.count(s)) {
                cout <<" "<<s;
                v.push_back(s);
            }
        }
        s[i] = ch;
    }
    return v;
}

bool
DFS(string s, string end, map<string, bool> m, vector<string> path,
    unordered_set<string> &dict, vector<vector<string>> &ans)
{
    path.push_back(s);
    m[s] = true;
    cout <<"\n DFS :  "<<s<<" "<<end<<"\n";
    if (!end.compare(s)) {
        cout <<"\n*Found "<<end;
        ans.push_back(path);
        return true;
    }

    vector<string> n = Neighbors(s, dict);
    for (int i = 0; i < n.size(); ++i) {
        if (m.find(n[i]) == m.end()) {
            if (DFS(n[i], end, m, path, dict, ans)) {
                //return true;
            }
        }
    }
    return false;
}

vector<vector<string>>
findLadders(string start, string end, unordered_set<string> &dict) {
    vector<vector<string>> ans;
    map<string, bool> m;
    dict.insert(start);
    dict.insert(end);

    vector<string> n = Neighbors(start, dict);
    for (int i = 0; i < n.size(); ++i) {
        vector<string> path;
        if (m.find(n[i]) == m.end()) {
            path.push_back(start);
            if(DFS(n[i], end, m, path, dict, ans)) {
               cout <<"\n Path : ";
               for(int j =0 ; j < path.size(); ++j)
                   cout <<"->"<<path[j];
               cout <<"\n";
            }
        }
    }

    return ans;
}

main () {
    string a[]= {"hot","dot","dog","lot","log"};
    unordered_set<string> dict(a, a+sizeof(a)/sizeof(string));
    vector<vector<string>> ans = findLadders("hit", "cog", dict);

    for (int i = 0; i < ans.size(); ++i) {
        cout <<"\n";
        for (int j = 0; j < ans[i].size(); ++j)
            cout <<"->"<<ans[i][j];
    }
    cout <<"\n";
}
