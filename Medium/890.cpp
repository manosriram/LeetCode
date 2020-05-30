#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
bool pattern_code(string s, string pat) {
    if (s.length() != pat.length()) return false;

    map<char, char> mx, mxx;
    for (int t=0;t<s.length();++t) {
        if ((mx[s[t]] && mx[s[t]] != pat[t]) || (mxx[pat[t]] && mxx[pat[t]] != s[t])) return false;

        mx[s[t]] = pat[t];
        mxx[pat[t]] = s[t];
    }
    return true;
}

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> vv;
    for (auto st: words) {
        if (pattern_code(st, pattern))
            vv.push_back(st);
    }

    return vv;
}

int main() {
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";

    auto res = findAndReplacePattern(words, pattern);

    for (auto st: res) cout << st << " ";
}
