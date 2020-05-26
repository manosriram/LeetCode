#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;
vector<int> temp;
int board[8][8] = { 0 };
bool isValidMove(int r, int c) {
    if (r > 7 || c > 7 || r < 0 || c < 0) return false;

    return true;
}

void rowUp(int r, int c) {
    if (!isValidMove(r, c)) return;
    if (board[r][c]) {
        temp.push_back(r);
        temp.push_back(c);
        res.push_back(temp);
        temp.clear();
        return;
    }

    rowUp(r-1, c);
}

void rowDown(int r, int c) {
    if (!isValidMove(r, c)) return;
    if (board[r][c]) {
        temp.push_back(r);
        temp.push_back(c);
        res.push_back(temp);
        temp.clear();
        return;
    }

    rowDown(r+1, c);
}

void colLeft(int r, int c) {
    if (!isValidMove(r, c)) return;
    if (board[r][c]) {
        temp.push_back(r);
        temp.push_back(c);
        res.push_back(temp);
        temp.clear();
        return;
    }

    colLeft(r, c-1);
}
void colRight(int r, int c) {
    if (!isValidMove(r, c)) return;
    if (board[r][c]) {
        temp.push_back(r);
        temp.push_back(c);
        res.push_back(temp);
        temp.clear();
        return;
    }

    colRight(r, c+1);
}
void diagnolDownRight(int r, int c) {
    if (!isValidMove(r, c)) return;
    // cout << r << " " << c << endl;
    if (board[r][c]) {
        temp.push_back(r);
        temp.push_back(c);
        res.push_back(temp);
        temp.clear();
        return;
    }

    diagnolDownRight(r+1, c+1);
}
void diagnolDownLeft(int r, int c) {
    if (!isValidMove(r, c)) return;
    if (board[r][c]) {
        temp.push_back(r);
        temp.push_back(c);
        res.push_back(temp);
        temp.clear();
        return;
    }

    diagnolDownLeft(r+1, c-1);
}
void diagnolUpRight(int r, int c) {
    if (!isValidMove(r, c)) return;
    if (board[r][c]) {
        temp.push_back(r);
        temp.push_back(c);
        res.push_back(temp);
        temp.clear();
        return;
    }

    diagnolUpRight(r-1, c+1);
}
void diagnolUpLeft(int r, int c) {
    if (!isValidMove(r, c)) return;
    if (board[r][c]) {
        temp.push_back(r);
        temp.push_back(c);
        res.push_back(temp);
        temp.clear();
        return;
    }

    diagnolUpLeft(r-1, c-1);
}
vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
    for (int t=0;t<queens.size();++t) {
        for (int tt=0;tt<queens[t].size();++tt) {
            board[queens[t][0]][queens[t][1]] = 1;
        }
    }
    int r = king[0], c = king[1];

    rowUp(r, c);
    rowDown(r, c);
    diagnolUpLeft(r, c);
    diagnolUpRight(r, c);
    diagnolDownLeft(r, c);
    diagnolDownRight(r, c);
    colLeft(r, c);
    colRight(r, c);

    return res;
}
int main() {
    vector<vector<int>> queens = {{0,1},{1,0},{4,0},{0,4},{3,3},{2,4}};
    vector<int> king = { 0, 0 };
    auto res = queensAttacktheKing(queens, king);

    for (auto t: res) cout << t[0] << " " << t[1] << endl;

}
