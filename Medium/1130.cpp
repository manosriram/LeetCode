int mctFromLeafValues(vector<int>& arr) {
    int sm=0, x, v;
    int mn;
    
    while (arr.size() > 1) {
        mn = INT_MAX;
        
        for (int t=0;t<arr.size()-1;++t) {
            v = arr[t] * arr[t+1];
            if (v < mn) {
                mn = v;
                x = arr[t] < arr[t+1] ? t : t+1;
            }
        }
        arr.erase(arr.begin() + x);
        sm += mn;
    }
    return sm;
}
