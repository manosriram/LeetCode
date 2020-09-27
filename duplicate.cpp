#include <iostream>
#include <map>
using namespace std;

int main() {
    string s = "you got beautiful eyes";
    map<char, int> freq;

    string res = "";
    for (int t=0;t<s.length();++t) {
        ++freq[s[t]];
        if (freq[s[t]] % 2 != 0)
            res += s[t];
    }
    cout << res;
}
