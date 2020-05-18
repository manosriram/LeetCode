#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> vv = nums;
    map<int, int> mp;
    sort(nums.begin(), nums.end());

    mp[nums[0]] = 0;
    for (int t=1;t<nums.size();++t) {
        if (nums[t] == nums[t-1])
            continue;

        mp[nums[t]] = t;
    }

    for (int t=0;t<vv.size();++t)
        vv[t] = mp[vv[t]];

    return vv;
}

int main() {
    vector<int> v {8, 1, 2, 2, 3};
    v = smallerNumbersThanCurrent(v);

    for (auto t: v) cout << t << " ";
}
