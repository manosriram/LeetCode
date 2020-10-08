int missingNumber(vector<int>& nums) {
    if (nums.size() == 1) return nums[0] == 1 ? 0 : 1;
    int res = nums.size();
    for (int t=0;t<nums.size();++t) {
        res ^= t ^ nums[t];
    }
    return res;
}
