string destCity(vector<vector<string>>& paths) {
    map<string, bool> mp;
    int n = paths.size();
    for (int t=0;t<n;++t) {
        mp[paths[t][0]] = true;
    }
    for (int t=0;t<n;++t) {
        if (!mp[paths[t][1]]) return paths[t][1];
    }
    return "";
}
