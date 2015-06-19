/* problem:
 * Express number as minimum number of sum of squares
 * */

#include <iostream>
#include <cmath>

using namespace std;

void sum(int n) {
    cout <<"\n "<<n<<" = ";
    while (n) {
        int ii = sqrt(n);
        cout <<" "<<ii<<"^2";
        n -= ii*ii;
        if (n) { cout<<"+"; }
    }
    cout <<"\n";
}

main () {
    sum(15);
    sum(8);
    sum(378);
    sum(420);
}
