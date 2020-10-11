int minSetSize(vector<int>& arr) {
    map<int, int> mp;
    priority_queue<int> q;
    
    int n = arr.size();
    for (int t=0;t<n;++t) {
        ++mp[arr[t]];
    }
    for (auto x: mp) {
        if (x.second > 0) q.push(x.second);
    }
    int sm = 0, ct = 0;
    
    while (sm < n/2) {
        sm += q.top();
        cout << sm << " ";
        q.pop();
        ++ct;
    }
    return ct;
}
