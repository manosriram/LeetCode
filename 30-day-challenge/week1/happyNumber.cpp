#include <iostream>
#include <set>
#include <math.h>
using namespace std;

class Solution {
    int numsq(int n) {
        int sk = 0;
        while (n) {
            sk += pow(n % 10, 2);
            n /= 10;
        }
        return sk;
    }
    
public:
    bool isHappy(int n) {
        set<int> ss;
        while (1) {
            n = numsq(n);
            if (n == 1) return true;
            if (ss.find(n) != ss.end()) return false;

            ss.insert(n);
        }
    }
};

int main() {
    Solution sl;
    bool res = sl.isHappy(19);
    cout << res;
}
