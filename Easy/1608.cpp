int specialArray(vector<int>& nums) {
    int mx = *max_element(nums.begin(), nums.end());
    
    int ct;
    for (int t=0;t<=mx;++t) {
        ct = 0;
        for (int tt=0;tt<nums.size();++tt) {
            if (nums[tt] >= t) ++ct;
        }
        if (ct == t) return t;
    }
    return -1;
}
