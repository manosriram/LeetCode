#include <iostream>
using namespace std;
int R = 5, C = 6;
bool visited[100][100] = { { false } };

int dfs(int r, int c, int mat[][100]) {
    if (mat[r][c] == 0 || visited[r][c] || r < 0 || c < 0 || r >= R || c >= C) return 0;

    visited[r][c] = true;
    return 1 + dfs(r, c+1, mat) + dfs(r, c-1, mat) + dfs(r+1, c, mat) + dfs(r-1, c, mat);
}

int main() {
    int mat[][100] = {
        {0, 0, 1, 0, 0, 0 },
        {0, 0, 0, 0, 1, 0 },
        {0, 0, 1, 1, 1, 0 },
        {0, 0, 1, 1, 1, 0 },
        {1, 1, 0, 0, 1, 1 },
    };

    int mx = INT_MIN;
    for (int t=0;t<R;++t) {
        for (int tt=0;tt<C;++tt) {
            mx = max(mx, dfs(t, tt, mat));
            cout << mx << " ";
        }
    }
}

