#include<iostream>
#include<string>
using namespace std;

class Badvocabulary {
    public:
        static int count(string &prefix, string &suffix, string &substr, string vocabulary[]);
};

bool isPrefix(string& prefix, string& main) {
    if (main.find(prefix) == string::npos) {
        return false;
    }
    if (!main.find(prefix)) {
        return true;
    }
    return false;
}

bool isSuffix(string& suffix, string& main) {
    if (main.find(suffix) == string::npos) {
        return false;
    }
    if (main.length() - main.find(suffix) == suffix.length()) {
        return true;
    }
    return false;
}

int Badvocabulary::count(string &prefix, string &suffix, string &substr, string vocabulary[]) {
    int count = 0;
    int size = 0;
    while (!vocabulary[size].empty()) {
        size++;
    }
    for (int i = 0; i < size; i++) {
        if (isPrefix(prefix, vocabulary[i])
            || isSuffix(suffix, vocabulary[i])
            || (!isPrefix(substr, vocabulary[i]) 
                && !isSuffix(substr, vocabulary[i])
                && vocabulary[i].find(substr) != std::string::npos)) {
            cout << "\n " << vocabulary[i];
            count++;
        } 
    }

    return count;
}

main () {
    string prefix = "pre";
    string suffix = "s";
    string substr = "all";
    string vocabulary[] ={"all", "coders", "be", "prepared", "for", "the", "challenge", "phase", ""};

    //string prefix = "a";
    //string suffix = "b";
    //string substr = "c";
    //string vocabulary[] ={"a", "b", "tco"};
   cout << "\n bad word count: " << Badvocabulary::count(prefix, suffix, substr, vocabulary) << "\n";
    //cout << "\n bad word count: " << count(prefix, suffix, substr, vocabulary) << "\n";
}
