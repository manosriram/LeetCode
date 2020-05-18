#include <vector>
#include <iostream>
using namespace std;
// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int mx = *max_element(candies.begin(), candies.end());
    vector<bool> bl(candies.size());

    for (int t=0;t<candies.size();++t) {
        bl[t] = (candies[t] + extraCandies >= mx);
    }
    return bl;
}

int main() {
    vector<int> candies = {2,3,5,1,3};
    int extraCandies = 3;
    auto res = kidsWithCandies(candies, extraCandies);

    for (auto t: res) cout << t << " ";
}
