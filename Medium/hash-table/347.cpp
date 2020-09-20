#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> pq;
    map<int, int> mp;
    for (int t=0;t<nums.size();++t) {
        mp[nums[t]]++;
    }
    for (auto x: mp) {
        pq.push(make_pair(x.second, x.first));
    }
    
    vector<int> res;
    while (k--) {
        auto tp = pq.top();
        res.push_back(tp.second);
        pq.pop();
    }
    return res;
}

int main() {
    vector<int> nums = { 1, 1, 1, 2, 2, 3 };
    nums = topKFrequent(nums, 2);
    for (auto x: nums)
        cout << x << " ";
}
