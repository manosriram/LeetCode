#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    map<int, int> mm;
    for (int t=0;t<arr1.size();++t) ++mm[arr1[t]];

    vector<int> res;
    for (int t=0;t<arr2.size();++t) {
        if (mm[arr2[t]]) {
            for (int tt=0;tt<mm[arr2[t]];++tt) res.push_back(arr2[t]);
        }
        mm[arr2[t]] = 0;
    }

    for (auto t=mm.begin();t!=mm.end();++t) {
        if (t->second > 0)
            for (int tt=0;tt<t->second;++tt)
                res.push_back(t->first);
    }
    return res;
}
int main() {
    int k = 2;
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};
    auto res = relativeSortArray(arr1, arr2);

    for (auto t: res) cout << t << " ";
}
