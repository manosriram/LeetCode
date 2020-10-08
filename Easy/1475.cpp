vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    for (int t=0;t<n;++t) {
        int in = t + 1;
        while (in < n && prices[in] > prices[t]) ++in;
        
        if (in < n) prices[t] -= prices[in];
    }
    return prices;
}
