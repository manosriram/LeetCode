#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int minPairSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	int n = nums.size();
	for (int t=0;t<n;++t) {
		cout << nums[t] << " ";
	}

	cout << endl;
	int it = 0, mx = INT_MIN;
	while (it < n/2) {
		mx = max(mx, nums[it] + nums[n - it - 1]);
		++it;
	}
	return mx;
}

int main() {
	vector<int> v {3, 5, 4, 2, 4, 6};
	cout << minPairSum(v) << endl;
}