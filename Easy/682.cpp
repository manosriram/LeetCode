int calPoints(vector<string>& ops) {
stack<int> s;

for (int t=0;t<ops.size();++t) {
    if (ops[t] == "D") {
        s.push(s.top() * 2);
    } else if (ops[t] == "C") {
        s.pop();
    } else if (ops[t] == "+") {
        int x = s.top();
        s.pop();
        int res = x + s.top();
        s.push(x);
        s.push(res);
    } else {
        s.push(stoi(ops[t]));
    }
}
int sm = 0;
while (!s.empty()) {
    sm += s.top();
    s.pop();
}
return sm;
}
