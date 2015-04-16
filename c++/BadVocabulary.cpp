/*
   Problem Statement:
   Little Teddy and Little Tracy are now learning how to speak words. Their mother, 
   of course, doesn't want them to speak bad words. According to her definition, a i
   word W is bad if at least one of the following conditions hold (see the notes section for definitions):
        W contains the string badPrefix as a prefix.
        W contains the string badSuffix as a suffix.
        W contains the string badSubstring as a contiguous substring that is neither a prefix nor a suffix of W.

    You are given a String[] vocabulary representing the words that Teddy and Tracy are going to learn. 
    Return the number of bad words in vocabulary.
 */

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
