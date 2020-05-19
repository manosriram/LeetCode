#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void goDiagnol(vector<vector<int>> &mat, int r, int c, int m, int n) {
    int rr = r, cc = c;
    int in = -1;
    vector<int> res;
    while (r < m && c < n) {
        res.push_back(mat[r][c]);
        ++r, ++c;
    }
    sort(res.begin(), res.end());
    while (rr < m && cc < n) {
        mat[rr][cc] = res[++in];
        ++rr, ++cc;
    }
    res.clear();
}

vector<vector<int>> diagonalSort(vector<vector<int>> mat, int m, int n) {
    for (int t=0;t<m;++t)
        goDiagnol(mat, t, 0, m, n);

    for (int t=1;t<n;++t)
        goDiagnol(mat, 0, t, m, n);

    return mat;
}

int main() {
    vector<vector<int>> mat { { 3, 3, 1, 1 }, { 2, 2, 1, 2 }, { 1, 1, 1, 2 } };

    mat = diagonalSort(mat, 3, 4);

    for (int t=0;t<3;++t) {
        for (int j=0;j<4;++j) {
            cout << mat[t][j] << " ";
        }
        cout << endl;
    }
}

