#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    map<int, int> rcx;

    for (int t=0;t<matrix.size();++t) {
        int mm = *min_element(matrix[t].begin(), matrix[t].end());
        ++rcx[mm];
    }

    for (int t=0;t<matrix[0].size();++t) {
        int mx = INT_MIN;
        for (int tt=0;tt<matrix.size();++tt) {
            mx = max(mx, matrix[tt][t]);
        }
        ++rcx[mx];
    }

    vector<int> res;
    for (auto t=rcx.begin();t!=rcx.end();++t) {
        if (t->second > 1) res.push_back(t->first);
    }

    return res;
}

int main() {
    int k = 2;
    vector<vector<int>> matrix = {{3,7,8},{9,11,13},{15,16,17}};
    auto res = luckyNumbers(matrix);

    for (int t=0;t<res.size();++t)
        cout << res[t] << " ";
}
