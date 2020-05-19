#include <iostream>
#include <vector>
#include <map>
using namespace std;

void moveFront(vector<int> &q, int in) {
    int x = q[in];
    for (int t=in-1;t>=0;--t)
        q[t+1] = q[t];

    q[0] = x;
    return;
}

vector<int> processQueries(vector<int> queries, int m) {
    vector<int> v, res;
    map<int, int> mm;
    for (int t=1;t<=m;++t) {
        v.push_back(t);
        mm[t] = t-1;
    }

    for (int t=0;t<queries.size();++t) {
        auto it = find(v.begin(), v.end(), queries[t]);
        int in = it - v.begin();

        res.push_back(in);
        moveFront(v, in);
    }
    return res;
}

int main() {
    vector<int> queries {4, 1, 2, 2};
    auto v = processQueries(queries, 4);

    for (auto t: v) cout << t << " ";
}

