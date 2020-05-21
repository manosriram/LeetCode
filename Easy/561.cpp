#include <iostream>
#include <vector>
#include <map>
using namespace std;

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int cc = 0;
    for (int t=0;t<nums.size();t+=2)
        cc += nums[t];

    return cc;
}

int main() {
    int k = 2;
    vector<int> arr = {1,4,3,2};
    auto res = arrayPairSum(arr);
    cout << res;
}
