#include <iostream>
#include <vector>
using namespace std;

vector<int> decompressRLElist(vector<int>& nums) {
    vector<int> vv;

    for (int t=0;t<nums.size();t += 2) {
        for (int tt=0;tt<nums[t];++tt)
            vv.push_back(nums[t+1]);
    }
    return vv;
}

int main() {
    vector<int> v {1 ,2 ,3 ,4};

    v = decompressRLElist(v);
    for (auto t: v) cout << t << " ";
}
