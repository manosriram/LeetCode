#include <iostream>
#include <vector>
using namespace std;

vector<string> buildArray(vector<int> &target, int n) {
    vector<string> result;
    int in = 0;
    for (int t=1;t<=n && in < target.size();++t) {
        if (t == target[in]) {
            result.push_back("Push");
            ++in;
        } else {
            result.push_back("Push");
            result.push_back("Pop");
        }
    }
    return result;
}

int main() {
    vector<int> target {1, 2};
    int n = 4;

    auto result = buildArray(target, n);
    for (auto t: result) cout << t << " ";
}
