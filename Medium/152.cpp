#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int> nums) {
    int mx = nums[0], mn = nums[0], res = nums[0];

    for (int t=1;t<nums.size();++t) {
        int temp = mx;
        mx = max(mx, max(nums[t], nums[t]*mn));
        mn = min(mn, min(nums[t], nums[t] *temp));
        res = max(res, mx);
    }
    return res;
}

int main() {
    vector<int> nums { 2, 3, -2, 4 };
    cout << maxProduct(nums);
}
