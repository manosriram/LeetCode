#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for (auto st: strs) {
            string ss = st;
            sort(st.begin(), st.end());
            mp[st].push_back(ss);
        }
        vector<vector<string>> vv;
        
        for (auto tt: mp) {
            vv.push_back(tt.second);
        }
        return vv;
    }
};

int main() {
    Solution sl;
    vector<string> strs {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto res = sl.groupAnagrams(strs);

    for (int t=0;t<res.size();++t) {
        for (auto tt:res[t]) cout << tt << " ";

        cout << endl;
    }
}
