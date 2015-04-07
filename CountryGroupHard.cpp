/*
   Problem Statement:
   Some people are sitting in a row. Each person came here from some country. People from the same country are all sitting together.
   A reporter has already approached some of the people and asked each of them the same question: "How many people from your countryi
   (including you) are here?" All the people who were asked the question gave her correct answers.
   You are given a int[] a. The elements of a correspond to the people in the row, in order. For each i, element i of a is either 0 if
   the corresponding person was not asked the question, or a positive integer: the answer given by that person.
   The reporter just realized that she might be able to reconstruct all the missing answers from the answers she already knows. 
   Return "Sufficient" if she can do that, or "Insufficient" if she cannot.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
template<class T, size_t N>
size_t size(T (&)[N]) { return N; }

class CountryGroupHard {
    public :
        static string solve(vector<int>& a);
};

string CountryGroupHard::solve(vector<int>& a) {
    int last_end = 0;
    for (int i = 0; i < a.size(); ++i) {
        int j = i, num;
        while(j < a.size() && !a[j++]);
        j--;
        num = a[j];
        cout << "\n a["<<j<<"] : "<<num<<", i: "<<i;
        if (!num)
            return "insufficient";
        for (int k = 0; k < num; ++k) {
            cout << "\n k + last_end : "<<a[k+last_end]<<"\n" ;
            if (a[k + last_end] && (a[k + last_end] != num)) {
                return "insufficient";
            }
        }
        last_end += num;
        cout << "\n last-end: "<<last_end<<"\n";
        i = last_end -1 ;
    }
    return "sufficient";
}

main () {
    //int a[] = {0,2,3,0,0};
    //int a[] = {0,2,0};
    //int a[] = {0,3,0,0,3,0};
    //int a[] = {0,0,3,3,0,0};
    int a[] = {2,2,0,2,2};


    vector<int> v(a, a + sizeof(a) / sizeof(int));
    cout << "\nsolve: " << CountryGroupHard::solve(v)<< "\n";
}
