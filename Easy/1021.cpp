#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    stack<char> st;
    string partial, result, s;
    cin >> s;

    for (int t=0;t<s.length();++t) {
        partial += s[t];
        if (s[t] == '(') st.push(s[t]);
        else st.pop();

        if (st.empty()) {
            result += partial.substr(1, partial.length() - 2);
            partial = "";
        }
    }
    cout << result;
}

