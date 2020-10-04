vector<string> commonChars(vector<string>& A) {
    map<char, int> mp, mpp;
    for (auto ch: A[0]) ++mp[ch];
    
    for (int t=1;t<A.size();++t) {
        mpp.clear();
        for (auto ch: A[t]) {
            ++mpp[ch];
        }
        for (auto ch: mp) {
            if (!mpp[ch.first]) mp[ch.first] = 0;
            else mp[ch.first] = min(mp[ch.first], mpp[ch.first]);
        }
    }
    vector<string> res;
    for (auto ch: mp) {
        if (ch.second != 0) {
            for (int t=0;t<ch.second;++t) {
                string s(1, ch.first);
                res.push_back(s);
            }
        }
    }
    return res;
}
