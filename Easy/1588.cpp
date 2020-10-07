int sumOddLengthSubarrays(vector<int>& arr) {
    vector<int> sum(arr.size());
    sum[0] = arr[0];
    for (int t=1;t<arr.size();++t) {
        sum[t] = sum[t-1] + arr[t];
    }
    int i = 0, j = 0, n = arr.size();
    int sm = 0;
    while (i < n) {
        sm += arr[i];
        j = i + 2;
        while (j < n) {
            if (i == 0) {
                sm += sum[j];
            } else {
                sm += sum[j] - sum[i-1];
            }
            j += 2;
        }
        ++i;
    }
    return sm;
}
