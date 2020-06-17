#include <iostream>
using namespace std;
int ct = 0, sm = 0;

int getDecimalValue(ListNode *head) {
    if (!head) return 0;

    getDecimalValue(head->next);
    sm += head->val * pow(2, ct++);
    return sm;
}
