ListNode* removeElements(ListNode* head, int val) {
    while (head && head->val == val) head = head->next;
    
    if (!head) return NULL;
    ListNode *prev = NULL, *cur = head, *nxt = head->next;
    while (cur) {
        cout << cur->val << " ";
        if (cur->val == val) {
            prev->next = nxt;
            cur = nxt;
        } else {
            prev = cur, cur = nxt;
        }
        if (nxt) nxt = nxt->next;
    }
    return head;
}
