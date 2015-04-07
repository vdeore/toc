#include <iostream>
#include <string>
using namespace std;

class sol {
    public:
    static string longest_palindrome(string&); 
};

string sol::longest_palindrome(string &input) {
    int ml, mr, mlength = 0; 
    cout <<"\ninput string : "<< input;
    for (int i = 1; i < input.length(); ++i) {
        string str1;
        int l, r;
        //even length
        l = i - 1; r = i;
        while(l >=0  && r<input.length() && input[l] == input[r]) {
            l--;
            r++;
        }
        cout <<"\n even sunstr starting at :" << input[i] << " is :" << r -l;
        if (r-l > mlength) {
            mlength = r- l;
            mr = r;
            ml = l-1;
        }
        l = i - 1; r = i + 1;
        while(l >=0 && r<input.length()&& input[l] == input[r]) {
            l--;
            r++;
        }
        cout <<"\n odd sunstr starting at :" << input[i] << " is :" << r -l -1;
        if (r-l > mlength) {
            mlength = r- l -1 ;
            mr = r;
            ml = l +1 ;
        }
    }
    return  input.substr(ml, mlength);
}

main () {
    string input = "abacdfgdcaba";
    cout << "\nlongest palindrome : " << sol::longest_palindrome(input) << "\n";
}
