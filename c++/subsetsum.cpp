/* problem statement:
 * Write an efficient C program to find the sum of contiguous subarray within a one-dimensional 
 * array of numbers which has the largest sum.
 */
#include<iostream>
#include<vector>
#include<map>
#include<list>

using namespace std;

class subsetsum {
    public:
        static int max_subsetsum(vector<int> &);
        static void print(vector<int> &);
};

void subsetsum::print(vector<int>& v) {
    cout <<"{ ";
    for (int i = 0; i < v.size(); ++i) {
        cout <<v[i];
        if (i < v.size() - 1) {
            cout <<", ";
        }
    }
    cout <<" }";
}

int subsetsum::max_subsetsum(vector<int>& v) {
    map<int, int> s;
    int max_sum_so_far = 0, max_sum = 0, mi = 0;
    list<int> solution;

    print(v);
#if 0
    //without using memoization
    max_sum_so_far = v[0] < 0 ? 0 : v[0];
    for (int i = 1; i < v.size(); ++i) {
        max_sum_so_far = max(v[i], max_sum_so_far + v[i]);
        max_sum = max(max_sum, max_sum_so_far);
    }
#endif
    cout<<"\n";
    s[0] = v[0] < 0 ? 0 : v[0];
    //cout <<s[0]<<", ";
    for (int i = 1; i < v.size(); ++i) {
        s[i] = max(v[i], s[i-1] + v[i]);
        if (max_sum < s[i]) {
            max_sum = s[i];
            mi = i;
        }
        //cout <<s[i]<<", ";
    }
    //print the solution by backtracking
    int temp = max_sum;
    while (temp) {
        solution.push_back(v[mi]);
        temp = temp - v[mi];
        mi--;
    }
   
    solution.reverse();
    cout<<"\nsolution:  ";
    for(list<int>::iterator it = solution.begin(); 
        it != solution.end(); ++it) {
        cout<<*it<<" ";
    }

    return max_sum;
}

main () {
    int a[] = {-3, -2, 4, -1, -2, 1, 5, -3};
    vector<int> v(a, a + sizeof(a)/sizeof(int));

    cout << "\nmax subset sum : "<< subsetsum::max_subsetsum(v)<<"\n";
}
