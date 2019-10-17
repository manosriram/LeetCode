#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t) {
    if (!s.length() && !t.length())
        return true;

    int i = 0, j = 0;
    while (j < t.length()) {
        if (i == s.length())
            return true;

        if (s[i] == t[j])
            ++i;

        ++j;
    }
    return (i == s.length());
}

int main() {
    cout << isSubsequence("ace", "abcde") << '\n';
}