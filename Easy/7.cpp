#include <string>
#include <iostream>
using namespace std;

int reverse(int x) {
    string s = std::to_string(x);
    int in = 0;
    bool neg = (s[0] == '-');
    while (in < s.length() && s[in++] == '0');

    s = s.substr(in-1, s.length());

    std::reverse(s.begin(), s.end());
    if (neg) s = '-' + s;
    long long ss = stoll(s);
    if (ss > 2147483647 || ss <= -2147483648) return 0;

    return stoi(s);
}

int main() {
    cout << reverse(-11200); // -211
}
