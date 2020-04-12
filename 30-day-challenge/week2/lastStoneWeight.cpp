#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int lastStoneWeight(vector<int> &stones) {
    priority_queue<int> pq;
    for (auto st: stones) pq.push(st);

    while (pq.size() > 1) {
        int fs = pq.top();pq.pop();
        int sc = pq.top();pq.pop();

        if (fs != sc) pq.push(fs - sc);
    }
    if (pq.empty()) return 0;

    return pq.top();
}

int main() {
    vector<int> stones {2, 7, 4, 1, 8, 1};
    cout << lastStoneWeight(stones);
}

