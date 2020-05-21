#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int ct;

    for (int t=0;t<mat.size();++t) {
        ct = 0;
        for (int tt=0;tt<mat[t].size();++tt) {
            if (mat[t][tt] == 0) break;

            ++ct;
        }
        pq.push(make_pair(ct, t));
    }
    vector<int> res;
    while (pq.size() > 0 && k--) {
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}

int main() {
    int k = 2;
    vector<vector<int>> mat = {{1,1,0,0,0},
        {1,1,1,1,0},
        {1,0,0,0,0},
        {1,1,0,0,0},
        {1,1,1,1,1}};

    auto res = kWeakestRows(mat, 3);

    for (int t=0;t<res.size();++t) {
        cout << res[t] << " ";
    }
}
