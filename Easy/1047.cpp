#include <iostream>
#include <stack>
using namespace std;

string removeDuplicate(string s, stack<char> st) {
    int n = s.end() - s.begin();
    int ct = -1;
    while (n--) {
        ++ct;
        if (!st.empty() && st.top() == s[ct]) {
            st.pop();
            continue;
        }
        st.push(s[ct]);
    }
    s = "";
    while (!st.empty()) {
        s = st.top() + s;
        st.pop();
    }
    return s;
}

int main() {
    stack<char> st;
    string s = "abbaca";

    s = removeDuplicate(s, st);
    cout << s;
}