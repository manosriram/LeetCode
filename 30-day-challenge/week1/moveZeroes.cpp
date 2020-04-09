#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int in = 0, inn = 1;
        while (inn < nums.size()) {
            if (nums[in] == 0 && nums[inn] != 0) {
                swap(nums[in], nums[inn]);
                ++in;
                ++inn;
            } else if (nums[in] == 0 && nums[inn] == 0) ++inn;
            else {
                ++in;
                ++inn;
            }
        }
        return;
    }
};

int main() {
    Solution sl;
    vector<int> nums { 0, 1, 0, 3, 12 };
    sl.moveZeroes(nums);

    for (auto e: nums) cout << e << " ";
}
