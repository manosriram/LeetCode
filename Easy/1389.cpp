#include <iostream>
#include <vector>
using namespace std;

vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    vector<int> vv(nums.size(), -1);

    for (int t=0;t<index.size();++t) {
        if (vv[index[t]] == -1) {
            vv[index[t]] = nums[t];
            continue;
        }

        for (int tt=nums.size()-1;tt>index[t];--tt)
            vv[tt] = vv[tt-1];

        vv[index[t]] = nums[t];
    }
    return vv;
}

int main() {
    vector<int> nums = {0,1,2,3,4}, index = {0,1,2,2,1};
    vector<int> res = createTargetArray(nums, index);

    for (auto t: res) cout << t << " ";
}
