#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int dp[prices.size()];
        dp[0] = 0;
        for (int t=1;t<prices.size();++t) {
            dp[t] = max(dp[t-1], dp[t-1] + prices[t] - prices[t-1]);
        }
        return dp[prices.size() - 1];
    }
};

int main() {
    Solution sl;
    vector<int> prices {7, 1, 5, 3, 6, 4};
    int res = sl.maxProfit(prices);

    cout << res;
}
