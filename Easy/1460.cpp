bool canBeEqual(vector<int>& target, vector<int>& arr) {
    map<int, int> mp;
    for (int t=0;t<arr.size();++t) {
        ++mp[arr[t]];
        --mp[target[t]];
    }
    
    for (int t=0;t<arr.size();++t) {
        if (mp[arr[t]] != 0) return false;
    }
    
    return true;
}
