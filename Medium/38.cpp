#include <iostream>
using namespace std;

string countAndSay(string s) {
    int ct = 1;
    string res;

    int t;
    for (t=0;t<s.length()-1;++t) {
        if (s[t] == s[t+1]) {
            ++ct;
            continue;
        } else {
            res += std::to_string(ct);
            res += s[t];
            ct = 1;
        }
    }

    res += std::to_string(ct);
    res += s[s.length() - 1];
    return res;
}

int main() {

    string x = "1";
    for (int t=1;t<=4;++t) {
        x = countAndSay(x);
    }

}
