#include <iostream>
#include <vector>
using namespace std;

int Solve(vector<int> nums, int x, int l, int r, int res) {
    if (res > x || l > r || l < 0 || r >= nums.size()) return INT_MAX;
        cout << l << " " << r << endl;;
    if (res == x) {
        return (l + (nums.size() - r - 1));
    }

    return min(
            Solve(nums, x, l+1, r, res + nums[l]),
            Solve(nums, x, l, r-1, res + nums[r])
    );
}

int minOperations(vector<int> nums, int x) {
    int res = Solve(nums, x, 0, nums.size() - 1, 0);
    if (res == INT_MAX) return -1;
    return res;
}

int main() {
    vector<int> nums {8828,9581,49,9818,9974,9869,9991,10000,10000,10000,9999,9993,9904,8819,1231,6309};

    cout << minOperations(nums, 134365);

}
