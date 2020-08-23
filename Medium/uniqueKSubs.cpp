#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main() {
    string a = "pqpqpqqrs";
    int k = 2;

    map<char, bool> mp;
    int n = a.length();
    string res;
    int ct;
    vector<string> v;
    for (int t=0;t<n;++t) {
        mp.clear();
        res = "";
        ct = 0;

        for (int j=t;j<n;++j) {
            if (!mp[a[j]]) {
                mp[a[j]] = true;
                ++ct;
            }

            if (ct > k) break;

            res += a[j];
        }
        if (ct >= k)
            v.push_back(res);
    }
    for (auto t: v) cout << t << " ";
}
