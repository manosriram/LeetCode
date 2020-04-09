#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sm = 0;
        int mx = INT_MIN;
        for (int t=0;t<nums.size();++t) {
            sm += nums[t];
            
            mx = max(mx, sm);
            if (sm < 0) sm = 0;
        }
        return mx;
    }
};

int main() {
    Solution sl;
    vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};
    int res = sl.maxSubArray(nums);
    cout << res;
}
