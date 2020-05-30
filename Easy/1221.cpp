#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int balancedStringSplit(string s) {
        int l = 0, r = 0, ct = 0;
        for (int t=0;t<s.length();++t) {
            if (s[t] == 'R') ++r;
            else ++l;
            
            if (l == r) {
                ++ct;
                l = 0, r = 0;
            }
        }
        return ct;
    }

int main() {
    auto count = balancedStringSplit("RLRRLLRLRL");
    cout << count;
}
