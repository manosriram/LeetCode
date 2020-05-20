#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.size() == 0)
        return 0;

    int min_ = std::numeric_limits<int>::max();
    for (int t = 0; t < prices.size(); t++) {
        if (prices[t] < min_)
            min_ = prices[t];

        prices[t] = prices[t] - min_;
    }
    return *max_element(prices.begin(), prices.end());
}

int main() {
    vector<int> v;
    v.__emplace_back(7);
    v.__emplace_back(1);
    v.__emplace_back(5);
    v.__emplace_back(3);
    v.__emplace_back(6);
    v.__emplace_back(4);

    cout << maxProfit(v) << '\n';
}