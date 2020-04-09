#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xx = nums[0];
        for (int t=1;t<nums.size();++t) xx ^= nums[t];
        
        return xx;
    }
};

int main() {
    Solution sl;
    vector<int> v{4, 1, 2, 1, 2};
    int res = sl.singleNumber(v);
    cout << res;
}
