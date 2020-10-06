vector<int> pathInZigZagTree(int label) {
    vector<int> res;
    int depth = log10(label)/log10(2);
    
    while (depth >= 0) {
        res.insert(res.begin(), label);
        label = (int) pow(2, depth - 1) + (int) pow(2, depth) - 1 - label/2;
        --depth;
    }
    return res;
}
