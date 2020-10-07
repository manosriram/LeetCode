int xorOperation(int n, int start) {
    int st = start;
    for (int t=1;t<n;++t) {
        start ^= (st + (2 * t));
    }
    return start;
}
