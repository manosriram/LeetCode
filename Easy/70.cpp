#include <iostream>
#include <string>
using namespace std;

int fibonacci(int n) {
        int dp[n+2];
        int i = 0;
        
        dp[0] = 0;
        dp[1] = 1;
        
        for (int t=2;t<=n;t++) {
            dp[t] = dp[t-1] + dp[t-2];
        }
        return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(++n) << '\n';
}