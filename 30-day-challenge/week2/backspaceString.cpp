#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> st;
        for (int t=0;t<S.length();++t) {
            if (S[t] == '#' && !st.empty()) st.pop();
            if (S[t] != '#') st.push(S[t]);
        }
        S = "";
        while (!st.empty()) {
            S += st.top();
            st.pop();
        }
        for (int t=0;t<T.length();++t) {
            if (T[t] == '#' && !st.empty()) st.pop();
            if (T[t] != '#') st.push(T[t]);
        }
        
        T = "";
        while (!st.empty()) {
            T += st.top();
            st.pop();
        }
        return (S == T);
    }
};

int main() {
    Solution sl;
    bool res = sl.backspaceCompare("ab#c", "ad#c");
    cout << res;
}
