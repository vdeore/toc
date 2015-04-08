#include<iostream>
#include<string>

using namespace std;

bool isNumber (string in) {
    int i = 0, no_of_dec = 0;
   
    if (in[0] == '-' || in[0] == '+') {
        i = 1;
    }
    while (i < in.length()) {
        cout << "\n in["<<i<<"] -> "<<in[i];
        if (i && (in[i] == '-' || in[i] == '+')) {
            return false;
        } 
        if (in[i] == '.') {
            if (no_of_dec) {
                return false;
            }
            no_of_dec++;
        } else if (in[i] < '0' || in[i] > '9') {
            return false;
        } 
        i++;
    }
    return true;
}

main() {
    cout << "\n isNumber : " << isNumber("++3.3425") << "\n";
    cout << "\n isNumber : "<< isNumber("80.01") << "\n";
}
