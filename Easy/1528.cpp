string restoreString(string s, vector<int>& indices) {
    map<int, char> mp;
    
    for (int t=0;t<s.length();++t) {
        mp[indices[t]] = s[t];
    }
    s = "";
    for (auto x: mp) {
        s += x.second;
    }
    return s;
}
