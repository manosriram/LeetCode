#include <iostream>
#include <string>
using namespace std;

int Solve(string s) {
    int ind = 0;
    string left, right;
    while (s[ind] >= '0' && s[ind] <= '9') {
        left += s[ind];
        ++ind;
    }
    char exp = s[ind];
    ++ind;

    int result = 0;
    while (ind < s.length()) {
        while (s[ind] >= '0' && s[ind] <= '9') {
            right += s[ind];
            ++ind;
        }

        switch(exp) {
            case '+':
                result = stoi(left) + stoi(right);
                break;
            case '-':
                result = stoi(left) - stoi(right);
                break;
            case '*':
                result = stoi(left) * stoi(right);
                break;
            case '/':
                result = stoi(left) / stoi(right);
                break;
        }
        exp = s[ind];
        ++ind;

        left = to_string(result);
        right = "";
    }
    cout << result << endl;
}

int main() {
    string exp = "100+200*2";

    Solve(exp);
}

