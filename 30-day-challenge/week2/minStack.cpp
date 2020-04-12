#include <iostream>
#define maxn 1000
using namespace std;

class MinStack {
    int a[maxn], mn[maxn];
    int tp;
public:
    MinStack() {
        tp = -1;
    }
    
    void push(int x) {
        if (tp == -1) {
            ++tp;
            a[tp] = x;
            mn[tp] = x;
        } else {
            if (x < mn[tp]) {
                mn[tp+1] = x;
            } else {
                mn[tp+1] = mn[tp];
            }
            a[tp+1] = x;
            ++tp;
        }
        return;
    }
    
    void pop() {
        --tp;
    }
    
    int top() {
        return a[tp];
    }
    
    int getMin() {
        return mn[tp];
    }
};

int main() {
    MinStack *ms = new MinStack();
    ms->push(-2);
    ms->push(0);
    ms->push(-3);
    cout << ms->getMin() << endl;
    ms->pop();
    cout << ms->top() << endl;
    cout << ms->getMin() << endl;
}
