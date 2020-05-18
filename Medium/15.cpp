#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<vector<int>> threeSum(vector<int> nums) {
    vector<vector<int>> res;
    if (nums.size() < 3) return res;
    vector<int> temp(3), tmp(3);
    map<int, int> mm;
    map<vector<int>, bool> srt;
    for (int t=0;t<nums.size();++t) ++mm[nums[t]];

    for (int t=0;t<nums.size();++t) {
        for (int tt=0;tt<nums.size();++tt) {
            if (t != tt) {
                --mm[nums[t]], --mm[nums[tt]];
                if (mm[nums[t]] < 0 || mm[nums[tt]] < 0) continue;
                int diff = -(nums[t] + nums[tt]);
                if (mm[diff] > 0) {
                    temp.push_back(nums[t]);
                    temp.push_back(nums[tt]);
                    temp.push_back(diff);
                    tmp = temp;
                    sort(tmp.begin(), tmp.end());
                    if (!srt[tmp]) {
                        res.push_back(temp);
                        temp.clear();
                        srt[tmp] = true;
                    }
                }
                temp.clear();
                tmp.clear();
                ++mm[nums[t]], ++mm[nums[tt]];
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums { -1, 0, 1, 2, -1, -4 };

    auto tt = threeSum(nums);
    for (int t=0;t<tt.size();++t) {
        for (int in=0;in<tt[t].size();++in) {
            cout << tt[t][in] << " ";
        }
        cout << endl;
    }

}
