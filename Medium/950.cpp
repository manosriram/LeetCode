#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> deckRevealedIncreasing(vector<int> deck) {
    deque<int> dq;
    int n = deck.size();

    vector<int> res(n);
    sort(deck.begin(), deck.end());
    for (int t=0;t<n;++t) dq.push_back(t);

    for (auto card: deck) {
        res[dq.front()] = card;
        dq.pop_front();
        if (!dq.empty()) {
            dq.push_back(dq.front());
            dq.pop_front();
        }
    }
    return res;
}

int main() {
    vector<int> deck = {17,13,11,2,3,5,7};

    auto res = deckRevealedIncreasing(deck);

    for (auto t: res) cout << t << " ";
}

