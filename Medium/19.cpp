ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head || !head->next) return NULL;
    ListNode *curr = head, *prev = NULL;
    
    int nn = getn(head) - n;
    if (nn == 0) {
        head = head->next;
        return head;
    }
    int tm = 0;
    while (tm < nn) {
        tm++;
        prev = curr;
        curr = curr->next;
    }
    if (prev && prev->next)
        prev->next = curr->next;
    
    return head;
}
