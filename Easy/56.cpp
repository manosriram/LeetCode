#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > merge_(vector<vector<int> > intervals) {
    vector<vector<int> > v;
    vector<int> temp;

    for (int t = 0; t < intervals.size() - 1; t++) {
        if (intervals[t][1] >= intervals[t + 1][0]) {
            temp.push_back(intervals[t][0]);
            temp.push_back(intervals[t + 1][1]);
            v.push_back(temp);
            ++t;
        } else {
            temp.push_back(intervals[t][0]);
            temp.push_back(intervals[t][1]);
            v.push_back(temp);
            temp.clear();
            temp.push_back(intervals[t + 1][0]);
            temp.push_back(intervals[t + 1][1]);
            v.push_back(temp);
        }
        temp.clear();
    }
    return v;
}

int main() {
    vector<vector<int> > intervals;
    vector<int> temp;

    temp.push_back(1);
    temp.push_back(4);
    intervals.push_back(temp);
    temp.clear();

    temp.push_back(4);
    temp.push_back(5);
    intervals.push_back(temp);
    temp.clear();

    temp.push_back(8);
    temp.push_back(10);
    intervals.push_back(temp);
    temp.clear();

    temp.push_back(15);
    temp.push_back(18);
    intervals.push_back(temp);
    temp.clear();

    intervals = merge_(intervals);

    for (int t = 0; t < intervals.size(); t++) {
        for (auto t1 = intervals[t].begin(); t1 != intervals[t].end(); t1++) {
            cout << *t1 << " ";
        }
        cout << '\n';
    }
}