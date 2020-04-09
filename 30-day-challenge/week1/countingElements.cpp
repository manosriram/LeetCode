#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int, bool> mm;
        for (auto tt: arr) mm[tt] = true;
        
        int ct = 0;
        for (int t=0;t<arr.size();++t) {
            if (mm[arr[t]+1]) ++ct;
        }
        return ct;
    }
};

int main() {
    Solution sl;
    vector<int> arr{1, 2, 3};
    int res = sl.countElements(arr);
    cout << res;
}
