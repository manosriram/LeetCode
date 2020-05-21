#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    int mn = INT_MAX;
    for (int t=0;t<arr.size()-1;t++) {
        mn = min(mn, abs(arr[t] - arr[t+1]));
    }

    vector<int> temp;
    vector<vector<int>> res;
    for (int t=0;t<arr.size()-1;t++) {
        if (abs(arr[t] - arr[t+1]) == mn) {
            temp.push_back(arr[t]);
            temp.push_back(arr[t+1]);
            res.push_back(temp);
            temp.clear();
        }
    }
    return res;
}

int main() {
    int k = 2;
    vector<int> arr = {3,8,-10,23,19,-4,-14,27};
    auto res = minimumAbsDifference(arr);

    for (int t=0;t<res.size();++t) {
        for (int tt=0;tt<res[t].size();++tt) {
            cout << res[t][tt] << " ";
        }
        cout << endl;
    }
}
