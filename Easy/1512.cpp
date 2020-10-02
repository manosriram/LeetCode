int numIdenticalPairs(vector<int>& nums) {
    map<int, int> mp;
    for (int t=0;t<nums.size();++t) {
        ++mp[nums[t]];
    }
    int ct = 0;
    for (int t=0;t<nums.size();++t) {
        if (mp[nums[t]] > 0) ct += --mp[nums[t]];
    }
    return ct;
}
