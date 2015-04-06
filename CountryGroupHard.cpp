#include <iostream>
#include <string>
#include <vector>

using namespace std;
template<class T, size_t N>
size_t size(T (&)[N]) { return N; }

class CountryGroupHard {
    public :
        static void solve(vector<int>& a);
};

void CountryGroupHard::solve(vector<int>& a) {
}

main () {
    int a[] = {0,2,3,0,0};
    vector<int> v (a, a + sizeof(a) / sizeof(int));
    
    CountryGroupHard::solve(v);

//    cout << "solve: " << CountryGroupHard::solve(a);
}
