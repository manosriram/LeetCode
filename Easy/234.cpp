stack<int> st;

int leng(ListNode *head) {
    ListNode *p = head;
    int ct = 0;
    while (p) {
        ++ct;
        p = p->next;
    }
    return ct;
}

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    int ln = leng(head);
    
    for (int t=0;t<ln/2;++t) {
        st.push(head->val);
        head = head->next;
    }
    if (ln % 2 != 0 && head && head->next) head = head->next;
    while (head) {
        if (st.top() != head->val) return false;
        head = head->next;
        st.pop();
    }
    return true;
}
