#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    vector<pair<int, int>> v;
    for (int t=0;t<groupSizes.size();++t) {
        v.push_back(make_pair(groupSizes[t], t));
    }
    sort(v.begin(), v.end());
    
    int i = 0;
    vector<vector<int>> res;
    int n = groupSizes.size();
    vector<int> temp;
    
    while (i < n) {
        int tt = v[i].first;
        
        while (tt--) {
            temp.push_back(v[i].second);
            ++i;
        }
        res.push_back(temp);
        temp.clear();
    }
    
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> groupSizes;
    int temp;
    for (int t=0;t<n;++t) {
        cin >> temp;
        groupSizes.push_back(temp);
    }
    auto res = groupThePeople(groupSizes);

    for (int t=0;t<res.size();++t) {
        for (int tt=0;tt<res[t].size();++tt) {
            cout << res[t][tt] << " ";
        }
        cout << endl;
    }
}
