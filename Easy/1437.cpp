#include <iostream>
#include <vector>
using namespace std;

bool kLengthApart(vector<int>& nums, int k) {
    int last = -1;

    for (int t=0;t<nums.size();++t) {
        if (nums[t] == 1) {
            if (last != -1 && t - last <= k) return false;

            last = t;
        }
    }
    return true;
}

int main() {
    int k = 2;
    vector<int> nums = {1,0,0,0,1,0,0,1};
    cout << kLengthApart(nums, k) << endl;
}
