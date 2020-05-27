#include <iostream>
#include <vector>
using namespace std;

void checkHigh(vector<int> nums, int &high, int val) {
    while (high >= 0 && nums[high] == val) --high;
    return;
}

int removeElement(vector<int>& nums, int val) {
    int low = 0, n = nums.size(), high = n - 1;
    if (!n) return 0;
    checkHigh(nums, high, val);
    int ct = 0;
    for (int t=0;t<n;++t) ct += (nums[t] == val);

    while(low < high) {
        if (nums[low] == val) {
            swap(nums[low], nums[high]);
            checkHigh(nums, high, val);
        }
        ++low;
    }
    return (n - ct);
}

int main() {
    vector<int> nums = { 0, 1, 2, 2, 3, 0, 4, 2 };
    int len = removeElement(nums, 3);

    for (int t=0;t<len;++t) cout << nums[t] << " ";
}

