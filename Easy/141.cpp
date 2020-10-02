bool hasCycle(ListNode *head) {
    if (!head) return false;
    ListNode *slow = head, *fast = head;
    
    while (fast && slow) {
        slow = slow->next;
        if (fast->next && fast->next->next) fast = fast->next->next;
        else return false;
        
        if (slow == fast) return true;
    }
    return false;
}
