#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int findUnsortedArray(vector<int> nums) {
    if (nums.size() == 0) return 0;

    int tt;
    for (tt=0;tt<nums.size()-1;++tt) {
        if (nums[tt] <= nums[tt+1]) continue;
        else break;
    }

    if (tt == nums.size()-1) return 0;

    stack<int> st;
    st.push(nums[0]);

    for (int t=1;t<nums.size();++t) {
        if (nums[t] >= st.top()) st.push(nums[t]);
        else {
            while (!st.empty() && st.top() > nums[t]) st.pop();

            st.push(nums[t]);
        }
    }
    return st.size();
}

int main() {
    vector<int> nums { 1, 2, 3, 4 };
    cout << findUnsortedArray(nums);
}
