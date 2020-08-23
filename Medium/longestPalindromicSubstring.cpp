#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string &s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return (s == rev);
}

// O(N^3)
string longestPalindrome(string s) {
    int n = s.length();
    int bestLen = 0;
    string bestS = "";

    for (int t=0;t<n-1;++t) {
        for (int tt=t;tt<n;++tt) {
            string subs = s.substr(t, tt - t + 1);
            if (tt - t + 1 > bestLen && isPalindrome(subs)) {
                bestLen = tt - t + 1;
                bestS = subs;
            }
        }
    }
    return bestS;
}

// Expanding from the center.
string longestPalindrome2(string s) {
    int n = s.length();
    int bestlen = 0;
    string bests = "";

    for (int mid=0;mid<n;mid++) {
        for (int x=1;mid - x >= 0 && mid + x < n;++x) {
            if (s[mid-x] != s[mid+x]) break;

            int len = 2 * x + 1;
            if (len > bestlen) {
                bestlen = len;
                bests = s.substr(mid - x, len);
            }
        }
    }

    for (int mid=0;mid<n-1;++mid) {
        for (int x = 1;mid - x + 1 >= 0 && mid + x < n; ++x) {
            if (s[mid-x+1] != s[mid+x]) break;

            int len = 2 * x;
            if (len > bestlen) {
                bestlen = len;
                bests = s.substr(mid - x + 1, len);
            }
        }
    }
    return bests;
}


int main() {
    cout << longestPalindrome("abadmalayalamabb");
}
