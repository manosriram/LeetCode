#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> minOperations(string boxes) {
    vector<int> res;
    int oneSum = 0, boxesPresent = 0;
    for (int t=0;t<boxes.length();++t) {
        if (boxes[t] == '1') {
            oneSum += t;
            ++boxesPresent;
        }
    }
    for (int t=0;t<boxes.length();++t) {
        res.push_back(abs(oneSum - (t * boxesPresent)));
    }
    return res;
}

int main() {
    auto res = minOperations("001011");
    for (auto t = 0;t < res.size();++t) {
        cout << res[t] << " ";
    }
}
