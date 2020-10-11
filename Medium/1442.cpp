int countTriplets(vector<int>& arr) {
    int n = arr.size();
    int sm = 0;
    for (int t=0;t<n;++t) {
        int res = arr[t];
        for (int tt=t+1;tt<n;++tt) {
            res ^= arr[tt];
            
            if (res == 0) sm += (tt - t);
        }
    }
    return sm;
}
